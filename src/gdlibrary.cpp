#include "gdexample.h"
#include "Bus.h"
#include "Lives.h"
#include "Parachutist.h"
#include "Player.h"
#include "points.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::nativescript_terminate(godot::_RegisterState::nativescript_handle); // Add this line
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<godot::GDExample>();
    godot::register_class<godot::Bus>();
    godot::register_class<godot::Lives>();
    godot::register_class<godot::Parachutist>();
    godot::register_class<godot::Player>();
    godot::register_class<godot::Points>();
}