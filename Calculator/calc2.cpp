#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/fl_draw.H>
#include <sstream>
#include <cmath>
#include <string>

// Custom button class with rounded corners
class RoundedButton : public Fl_Button {
private:
    Fl_Color normal_color = fl_rgb_color(70, 70, 70);   // Dark gray for normal color
    Fl_Color hover_color = fl_rgb_color(100, 100, 100); // Brighter gray for hover effect

public:
    RoundedButton(int X, int Y, int W, int H, const char *L = 0) : Fl_Button(X, Y, W, H, L) {
        color(normal_color);
    }

    int handle(int event) override {
        switch (event) {
            case FL_ENTER:  // Mouse enters button area
                color(hover_color);  // Change to hover color
                redraw();
                return 1;
            case FL_LEAVE:  // Mouse leaves button area
                color(normal_color);  // Revert to normal color
                redraw();
                return 1;
            default:
                return Fl_Button::handle(event);
        }
    }

    void draw() override {
        int radius = 10;  // Radius for rounded corners

        // Draw rounded rectangle background
        fl_color(color());
        fl_pie(x(), y(), 2 * radius, 2 * radius, 90, 180);  // Top-left corner
        fl_pie(x() + w() - 2 * radius, y(), 2 * radius, 2 * radius, 0, 90);  // Top-right corner
        fl_pie(x(), y() + h() - 2 * radius, 2 * radius, 2 * radius, 180, 270); // Bottom-left corner
        fl_pie(x() + w() - 2 * radius, y() + h() - 2 * radius, 2 * radius, 2 * radius, 270, 360); // Bottom-right corner
        fl_rectf(x() + radius, y(), w() - 2 * radius, h());
        fl_rectf(x(), y() + radius, w(), h() - 2 * radius);

        // Draw label
        fl_color(FL_BLACK);
        fl_font(labelfont(), labelsize());
        fl_color(labelcolor());
        fl_draw(label(), x(), y(), w(), h(), FL_ALIGN_CENTER);
    }
};

// Custom output class with rounded corners
class RoundedOutput : public Fl_Output {
public:
    RoundedOutput(int X, int Y, int W, int H, const char *L = 0) : Fl_Output(X, Y, W, H, L) {}

    void draw() override {
        int radius = 10;  // Radius for rounded corners

        // Draw rounded rectangle background
        fl_color(color());
        fl_pie(x(), y(), 2 * radius, 2 * radius, 90, 180);  // Top-left corner
        fl_pie(x() + w() - 2 * radius, y(), 2 * radius, 2 * radius, 0, 90);  // Top-right corner
        fl_pie(x(), y() + h() - 2 * radius, 2 * radius, 2 * radius, 180, 270); // Bottom-left corner
        fl_pie(x() + w() - 2 * radius, y() + h() - 2 * radius, 2 * radius, 2 * radius, 270, 360); // Bottom-right corner
        fl_rectf(x() + radius, y(), w() - 2 * radius, h());
        fl_rectf(x(), y() + radius, w(), h() - 2 * radius);

        // Draw text
        fl_color(FL_BLACK);
        fl_font(textfont(), textsize());
        fl_color(textcolor());
        fl_draw(value(), x() + 10, y(), w() - 20, h(), FL_ALIGN_LEFT);
    }
};

class Calculator {
public:
    Fl_Window *win;
    RoundedOutput *input_display;
    RoundedOutput *result_display;
    std::string input;
    bool justComputed;

    Calculator() : justComputed(false) {
        win = new Fl_Window(500, 620, "Calculator_baba");
        win->color(FL_DARK3);

        input_display = new RoundedOutput(30, 30, 440, 50);
        input_display->textsize(24);
        input_display->color(FL_WHITE);
        input_display->textcolor(FL_BLACK);

        result_display = new RoundedOutput(30, 90, 440, 50);
        result_display->textsize(24);
        result_display->color(FL_WHITE);
        result_display->textcolor(FL_BLACK);

        const char *labels[] = { "7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+", "C", "", "sqr", "sqrt" };
        int posX = 30, posY = 160;
        Fl_Color custom_orange = fl_rgb_color(255, 165, 0);

        for (int i = 0; i < 20; ++i) {
            if (i % 4 == 0 && i != 0) {
                posX = 30;
                posY += 90;
            }
            RoundedButton *btn = new RoundedButton(posX, posY, 100, 80, labels[i]);
            btn->labelfont(FL_BOLD);
            btn->labelsize(24);
            btn->color(FL_GRAY);
            btn->labelcolor(FL_WHITE);

            if (i == 16) {
                btn->callback(CB_clear, (void*)this);
                btn->color(FL_RED);
            } else if (i == 14) {
                btn->callback(CB_compute, (void*)this);
                btn->color(custom_orange);
            } else if (i == 18) {
                btn->callback(CB_square, (void*)this);
            } else if (i == 19) {
                btn->callback(CB_sqrt, (void*)this);
            } else {
                btn->callback(CB_input, (void*)this);
            }
            posX += 110;
        }
        win->end();
    }

    static void CB_input(Fl_Widget *w, void *data) {
        Calculator *calc = (Calculator*)data;
        if (calc->justComputed) {
            calc->input = "";
            calc->justComputed = false;
        }
        const char *label = ((Fl_Button*)w)->label();
        calc->input += label;
        calc->input_display->value(calc->input.c_str());
    }

    static void CB_clear(Fl_Widget *w, void *data) {
        Calculator *calc = (Calculator*)data;
        calc->input = "";
        calc->input_display->value(calc->input.c_str());
        calc->result_display->value("");
    }

    static void CB_compute(Fl_Widget *w, void *data) {
        Calculator *calc = (Calculator*)data;
        std::string result = compute(calc->input);
        calc->input_display->value(calc->input.c_str());
        calc->result_display->value(result.c_str());
        calc->justComputed = true;
    }

 static void CB_square(Fl_Widget *w, void *data) {
    Calculator *calc = (Calculator*)data;
    try {
        double num = std::stod(calc->input);
        double result = num * num;
        // Show the squared result in result_display without modifying input
        calc->result_display->value(std::to_string(result).c_str());
        calc->justComputed = true;
    } catch (const std::exception &e) {
        calc->result_display->value("Error");  // Handle invalid input gracefully
    }
}


    static void CB_sqrt(Fl_Widget *w, void *data) {
        Calculator *calc = (Calculator*)data;
        double num = std::stod(calc->input);
        calc->input = std::to_string(std::sqrt(num));
        calc->result_display->value(calc->input.c_str());
    }

    static std::string compute(const std::string &input) {
        double result = 0;
        std::istringstream iss(input);
        iss >> result;
        return std::to_string(result);
    }

    void run() {
        win->show();
        Fl::run();
    }
};

int main(int argc, char **argv) {
    Calculator calc;
    calc.run();
    return 0;
}
