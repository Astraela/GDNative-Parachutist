#include "Bus.h"

#include <Godot.hpp>
#include <Viewport.hpp>
#include <SceneTree.hpp>
#include <Node2D.hpp>
#include <memory>
#include <String.hpp>
#include <set>
#include <RandomNumberGenerator.hpp>
#include <Sprite.hpp>
#include <PackedScene.hpp>
#include <ResourceLoader.hpp>

using namespace godot;


void Bus::_register_methods() {
    register_method("_process", &Bus::_process);
    register_method("_ready", &Bus::_ready);
}


void Bus::_init() {}

void Bus::_ready(){
    parachutist = ResourceLoader::get_singleton()->load("res://Parachutist.tscn");
    _random = (godot::Ref<godot::RandomNumberGenerator>)godot::RandomNumberGenerator::_new();
    _random->randomize();
}

void Bus::_process(float delta) {
    Vector2 Acceleration = Vector2(0,0);
    Acceleration.x = speed;
    float friction = .05f * Velocity.x;
    Acceleration.x -= friction;
    Velocity.x += Acceleration.x;
    Vector2 position = get_position();
    set_position(position + Vector2(Velocity.x * delta, 0));
    if ((position.x <= 0.0 + padding / 1.5 && speed < 0) || (position.x >= get_viewport_rect().size.x - padding * 3 && speed > 0)) {
        speed = speed * -1;
        Sprite* sprite = cast_to<Sprite>(get_node("Sprite"));
        sprite->set_flip_h(speed <= 0);
    }
    waitTime -= delta;
    if (waitTime <= 0) {
        
        Node2D* newP = cast_to<Node2D>(parachutist->instance());
        get_tree()->get_root()->add_child(newP);
        newP->set_position(get_position() + Vector2(0,50));
        waitTime = _random->randf_range(waitLimit.x, waitLimit.y);
        Godot::print("Parachutist Spawned");
    }
}


