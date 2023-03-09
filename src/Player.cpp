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
#include <Math.hpp>
#include <InputEventAction.hpp>
#include <Variant.hpp>
#include "points.h"

#include "Player.h"
using namespace godot;

void Player::_register_methods()
{
    register_method("_input", &Player::_input);
    register_method("_process", &Player::_process);
    register_method("_on_Player_area_entered", &Player::_on_Player_area_entered);
}


void Player::_init() {}

void Player::_input(Variant var) {
    InputEvent* event = Object::cast_to<InputEvent>(var.operator InputEvent*());
    if (event->is_action_pressed("Left")) {
        left = true;
    }
    else if (event->is_action_released("Left")) {
        left = false;
    }
    if (event->is_action_pressed("Right")) {
        right = true;
    }
    else if (event->is_action_released("Right")) {
        right = false;
    }
}

float Player::clamp(float n, float min, float max) {
    return n < min ? min : n > max ? max : n;
}

void Player::_process(float delta){
    Vector2 acceleration = Vector2(0, 0);
    if(left){acceleration.x = -speed;}
    if(right){acceleration.x = speed;}
    velocity.x += acceleration.x;
    float friction = .01f * velocity.x;
    velocity.x -= friction;

        Vector2 position = get_position();
        position += velocity * delta;
        position.x = clamp(position.x, 0, get_viewport_rect().size.x);
        
    set_position(position);
}


void Player::_on_Player_area_entered(Variant var) {
    Node2D* obj = Object::cast_to<Node2D>(var.operator Object*());
    
    if (obj->is_in_group("Parachutists")) {
        obj->queue_free();
        
        Node* node = Node2D::get_tree()->get_root()->get_node("Node2D/UI/Points");
        Points* points = cast_to<Points>(node);
        points->AddOne();
    }
}