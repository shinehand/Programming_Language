#pragma once
#include <vector>
#include <iostream>
#include <memory>

// 2D 점 구조체
struct Point {
    float x, y;
    Point(float x = 0, float y = 0) : x(x), y(y) {}
};

// 축 정렬 경계 박스 (Axis-Aligned Bounding Box)
struct AABB {
    float cx, cy;   // 중심 좌표
    float half_w;   // 반너비
    float half_h;   // 반높이

    AABB(float cx, float cy, float half_w, float half_h)
        : cx(cx), cy(cy), half_w(half_w), half_h(half_h) {}

    bool contains(const Point& p) const {
        return p.x >= cx - half_w && p.x <= cx + half_w
            && p.y >= cy - half_h && p.y <= cy + half_h;
    }

    bool intersects(const AABB& other) const {
        return !(other.cx - other.half_w > cx + half_w
              || other.cx + other.half_w < cx - half_w
              || other.cy - other.half_h > cy + half_h
              || other.cy + other.half_h < cy - half_h);
    }
};

// 쿼드트리 (QuadTree)
class QuadTree {
private:
    static const int MAX_POINTS = 4; // 노드당 최대 점 개수

    AABB boundary;
    std::vector<Point> points;
    bool divided;

    std::unique_ptr<QuadTree> nw; // 북서
    std::unique_ptr<QuadTree> ne; // 북동
    std::unique_ptr<QuadTree> sw; // 남서
    std::unique_ptr<QuadTree> se; // 남동

    // 4개 자식 노드로 분할
    void subdivide() {
        float hw = boundary.half_w / 2;
        float hh = boundary.half_h / 2;
        float cx = boundary.cx;
        float cy = boundary.cy;

        nw = std::make_unique<QuadTree>(AABB(cx - hw, cy + hh, hw, hh));
        ne = std::make_unique<QuadTree>(AABB(cx + hw, cy + hh, hw, hh));
        sw = std::make_unique<QuadTree>(AABB(cx - hw, cy - hh, hw, hh));
        se = std::make_unique<QuadTree>(AABB(cx + hw, cy - hh, hw, hh));
        divided = true;

        // 기존 점들을 자식에게 재분배
        for (const auto& p : points) {
            if (!nw->insert(p) && !ne->insert(p) &&
                !sw->insert(p) && !se->insert(p)) {}
        }
        points.clear();
    }

public:
    QuadTree(const AABB& boundary)
        : boundary(boundary), divided(false) {}

    // 점 삽입
    bool insert(const Point& p) {
        if (!boundary.contains(p)) return false;

        if (!divided) {
            if ((int)points.size() < MAX_POINTS) {
                points.push_back(p);
                return true;
            }
            subdivide();
        }

        return nw->insert(p) || ne->insert(p)
            || sw->insert(p) || se->insert(p);
    }

    // 범위 내 점 검색
    void query(const AABB& range, std::vector<Point>& result) const {
        if (!boundary.intersects(range)) return;

        if (!divided) {
            for (const auto& p : points) {
                if (range.contains(p)) result.push_back(p);
            }
            return;
        }

        nw->query(range, result);
        ne->query(range, result);
        sw->query(range, result);
        se->query(range, result);
    }

    // 총 점 개수
    int count() const {
        if (!divided) return (int)points.size();
        return nw->count() + ne->count() + sw->count() + se->count();
    }

    // 트리 구조 출력 (디버그용)
    void print(int depth = 0) const {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "AABB(cx=" << boundary.cx
                  << ", cy=" << boundary.cy
                  << ", hw=" << boundary.half_w
                  << ", hh=" << boundary.half_h << ")\n";
        if (!divided) {
            for (const auto& p : points) {
                std::cout << indent << "  Point(" << p.x << ", " << p.y << ")\n";
            }
        } else {
            nw->print(depth + 1);
            ne->print(depth + 1);
            sw->print(depth + 1);
            se->print(depth + 1);
        }
    }
};
