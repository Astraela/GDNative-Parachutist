#ifndef Bus_H
#define Bus_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <PackedScene.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot {

class Bus : public Node2D {
    GODOT_CLASS(Bus, Node2D)

private:
    Ref<PackedScene> parachutist;// = load("res://Parachutist.tscn");
    float speed = 30;
    float padding = 70;
    Vector2 Velocity = Vector2(0, 0);
    float waitTime = 3;
    Vector2 waitLimit = Vector2(.25, 2);
    godot::Ref<godot::RandomNumberGenerator> _random;

public:
    static void _register_methods();

    void _init();

    void _process(float delta);
    void _ready();
};

}

#endif