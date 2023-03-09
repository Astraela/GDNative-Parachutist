#ifndef Player_H
#define Player_H

#include <Godot.hpp>
#include <Node2D.hpp>

namespace godot {

class Player : public Node2D {
    GODOT_CLASS(Player, Node2D)

private:
    float speed = 10;
    Vector2 velocity = Vector2(0,0);
    bool left = false;
    bool right = false;

    float clamp(float n, float min, float max);
public:
    static void _register_methods();

    void _init(); 

    void _process(float delta);
    void _input(Variant event);
    void _on_Player_area_entered(Variant obj);
};

}

#endif