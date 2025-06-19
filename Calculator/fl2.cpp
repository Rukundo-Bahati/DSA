#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <iostream>

using namespace std;

class CustomBox : public Fl_Box {
public:
    CustomBox(int X, int Y, int W, int H, const char* L=0) : Fl_Box(X, Y, W, H, L) {}
    int handle(int event) override {
        if (event == FL_KEYDOWN) {
            int key = Fl::event_key();
            cout << "Key pressed: " << key << endl;
            return 1; // Event handled
        }
        return Fl_Box::handle(event);
    }
};


int main() {
    Fl_Window window(500, 500, "Custom Event Example");
    CustomBox box(20, 40, 260, 100, "Press any key");
    window.show();
    return Fl::run();
}
