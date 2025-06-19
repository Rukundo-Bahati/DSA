#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <cmath>
#include <string>
#include <stdexcept> 

using namespace std;

class Calculator {
public:
    Calculator() {
        window = new Fl_Window(500, 600, "Calculator");
        
        // Input display with rounded corners
        display = new Fl_Input(30, 20, 440, 50, "");
        display->readonly(1);
        display->textsize(24);
        display->box(FL_ROUNDED_BOX);  // Rounded corners for input field
        display->value(" "); 

        // Create buttons for digits and operations
        const char* buttons[19] = {"7", "8", "9", "/",
                                   "4", "5", "6", "DEL", 
                                   "1", "2", "3", "sqrt", 
                                   "0", "-", "+", "*",
                                   "%", "x^2", "="};
        int x = 30, y = 100;
        for (int i = 0; i < 19; i++) {
            Fl_Button* btn;
            if (buttons[i] == string("=")) {
                btn = new Fl_Button(x, y, 210, 80, buttons[i]); // Double the width
            } else {
                btn = new Fl_Button(x, y, 100, 80, buttons[i]);
            }

            // Rounded corners for buttons
            btn->box(FL_ROUNDED_BOX);

            // Button hover effect: Change color on hover
            btn->color(FL_LIGHT2);              // Default background color
            btn->selection_color(FL_DARK3);     // Color when clicked/hovered

            btn->callback(button_cb, (void*)this);
            x += 110;
            if ((i + 1) % 4 == 0) { x = 30; y += 90; }
        }

        window->end();
        window->show();
    }

    void append_text(const char* s) {
        string current = display->value();
        current += s;
        display->value(current.c_str());
    }

    void clear_text() {
        display->value("");
    }

    void calculate_result() {
        string expression = display->value();
        try {
            double result = evaluate(expression);
            display->value(to_string(result).c_str());
        } catch (const invalid_argument& e) {
            fl_alert("Error: Invalid input!");
            clear_text();
        }
    }

    // Function to handle basic operations
    void handle_operator(const char* op) {
        string current = display->value();
        if (!current.empty() && isdigit(current.back())) {
            current += " ";
            current += op;
            current += " ";
            display->value(current.c_str());
        }
    }

    void handle_sqrt() {
        string current = display->value();
        try {
            double value = stod(current);
            if (value >= 0) {
                display->value(to_string(sqrt(value)).c_str());
            } else {
                fl_alert("Error: Negative number for square root!");
                clear_text();
            }
        } catch (const invalid_argument& e) {
            fl_alert("Error: Invalid input for square root!");
            clear_text();
        }
    }

    void handle_square() {
        string current = display->value();
        try {
            double value = stod(current);
            display->value(to_string(value * value).c_str());
        } catch (const invalid_argument& e) {
            fl_alert("Error: Invalid input for square!");
            clear_text();
        }
    }

    void handle_modulus() {
        string current = display->value();
        size_t pos = current.find(" % ");
        if (pos != string::npos) {
            try {
                double num1 = stod(current.substr(0, pos));
                double num2 = stod(current.substr(pos + 3));
                if (num2 == 0) throw invalid_argument("Division by zero");
                display->value(to_string(fmod(num1, num2)).c_str());
            } catch (const invalid_argument& e) {
                fl_alert("Error: Invalid input for modulus!");
                clear_text();
            }
        } else {
            handle_operator("%");
        }
    }

    static void button_cb(Fl_Widget* widget, void* data) {
        Calculator* calc = (Calculator*)data;
        const char* label = ((Fl_Button*)widget)->label();
        if (isdigit(label[0]) || (label[0] == '.' && !calc->contains_dot())) {
            calc->append_text(label);
        } else if (label == string("DEL")) {
            calc->clear_text();
        } else if (label == string("=")) {
            calc->calculate_result();
        } else if (label == string("sqrt")) {
            calc->handle_sqrt();
        } else if (label == string("x^2")) {
            calc->handle_square();
        } else if (label == string("%")) {
            calc->handle_modulus();
        } else {
            calc->handle_operator(label);
        }
    }

private:
    Fl_Window* window;
    Fl_Input* display;

    bool contains_dot() {
        string current = display->value();
        for (auto ch : current) {
            if (ch == '.') return true;
        }
        return false;
    }

    double evaluate(const string& expression) {
        double num1 = 0, num2 = 0;
        char op = 0;
        sscanf(expression.c_str(), "%lf %c %lf", &num1, &op, &num2);
        switch (op) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/':
                if (num2 == 0) throw invalid_argument("Division by zero");
                return num1 / num2;
            case '%':
                if (num2 == 0) throw invalid_argument("Division by zero");
                return fmod(num1, num2);
            default:
                throw invalid_argument("Invalid operator");
        }
    }
};

int main() {
    Calculator calc;
    return Fl::run();
}
