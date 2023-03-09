#ifndef Lives_H
#define Lives_H

#include <Godot.hpp>
#include <RichTextLabel.hpp>

namespace godot {

class Lives : public RichTextLabel {
    GODOT_CLASS(Lives, RichTextLabel)

private:
        int lives = 3;

public:
    static void _register_methods();

    void _init(); 

    void Hurt();
};

}

#endif