#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Slider.H>
#include <iostream>

using namespace std;

void onButtonClick(Fl_Widget* widget, void*){
 cout << "Button clicked" <<endl;
}
void onInputClick(Fl_Widget* widget, void*){
 cout << "Input clicked" <<endl;
}

int main() {
    Fl_Window window(800,700, "Hello Baba!");  //creating the size of the window
    Fl_Box box(20,40,260,100, "Hello again");  //displays a static label inside the window.

    Fl_Button button(100, 80, 100, 40, "Click Me");
    button.callback(onButtonClick);

    Fl_Input input(200, 80, 200, 40);
    input.callback(onInputClick);

    Fl_Slider slider(300,50,300,50,"90");
    Fl_Choice choice(400,200,400,200, "select");



    choice.argument('h');
    
    window.show();      //
    return Fl::run();  //starts the FLTK event loop to keep the window open.


}