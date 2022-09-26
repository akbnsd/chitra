// This file is a part of  chitra (चित्र)
// Copyright (C) 2022  akshay bansod <akshay.bnsod@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// window class for window management 

#ifndef WINDOW_HPP
#define WINDOW_HPP

class GLFWwindow;

class window
{
public:

    // holds functions to handler various input events 
    struct inputHandler
    {
        window* display=0;
        // mouse position and delta values
        double posX, posY, dposX, dposY,
        // scroll positions
        scrollX, scrollY, dScrollX, dScrollY;
        // window width and height
        int height=0, width=0;

        virtual void close() {};
        virtual void resized() {};
        virtual void cursorUpdate() {};
        virtual void scrollUpdate() {};
        virtual void dropInput(const char* str) {};
        virtual void keyStateUpdate(int keyCode, bool down) {};
        virtual void mouseButtonUpdate(int keyCode, bool down) {};
    } defaultInputHandler;

    // initial configuration of window
    struct windowConfig
    {
        int width = 0, height=0;
        unsigned int monitorIndex=0;
        const char* title = "window";

        bool setFullscreen=false;
        inputHandler* handler=0;
    };


    window(windowConfig&);

    // switch current inputHandler with new one
    // the previous handler is returned 
    inputHandler* switchHandler(inputHandler* handler);

    ~window();


private:
    GLFWwindow* m_win=0;
    // m_handler must never be null
    inputHandler* m_handler= &defaultInputHandler;
    int m_height=0, m_width=0;

    // static callbacks to window inputs
    // later inputs passed to m_handler
    static void glfwWindowCloseCallback(GLFWwindow*);
    static void glfwCursorPosCallback(GLFWwindow*, double, double);
    static void glfwResizeCallback(GLFWwindow* window, int width, int height);
    static void glfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    static void glfwDropCallback(GLFWwindow* window, int path_count, const char* paths[]);
    static void glfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};  

#endif //WINDOW_HPP