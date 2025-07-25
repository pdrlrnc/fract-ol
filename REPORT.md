# Project Report: `fract-ol`

## 1. Objective

The goal of this project was to create a small graphics program called `fract-ol` that renders and lets you explore classic fractals in real time. The program must:

- Parse command-line arguments to select which fractal to draw (e.g., Mandelbrot and Julia).
- Initialize a window (using the MiniLibX graphics library) and compute each pixel’s color by iterating the fractal formula.
- Support interactive controls, like zooming in and out.
- Cleanly handle window events (close, key press, mouse events) and exit without leaks.

## 2. Implementation Summary

- **Language:** C  
- **Key features:**
  - Supports two fractals: Mandelbrot (`--mandelbrot` or `-M`) and Julia (`--julia` or `-J`)
  - Handles **window size**: you can pass window size (`--window` or `-W`)
  - Supports selecting **iteration** number; the program will always start at 1 and you can increase/decrease using the `+` and `–` keys.

- **Interesting design decisions:**
  - Uses a structure `t_params` that has all parameters needed for the program to run. I created a function called **`t_params **param_factory(void)`** that adapts the Factory pattern to C: it returns a `static` instance of `t_params` used throughout, so I don’t have to pass it around in every function.

## 3. Challenges Faced

- **How to handle MiniLibX**  
  I don’t want to throw shade at the amazing folks who designed this library, but… let’s say it isn’t the easiest to work with.

- **Programming graphical programs**  
  It was my first time ever programming a GUI. I needed to grasp new concepts like calculating pixels, drawing them on a window, and handling user input. But honestly, seeing that one pixel on my window for the first time was an amazing feeling.

- **Math is hard**  
  I had some concept of complex numbers—it’s not exactly rocket science—but I went down a YouTube rabbit hole on fractals. I shouldn’t have done it on my personal YouTube account, because now all I get recommended are Numberphile videos.

## 4. What I Learned

- The basics of graphical programming.  
- Perseverance and hard work pay off—it was the first school project where I genuinely felt lost and didn’t know how to start. I didn’t become a graphics *whiz*, but I’m much more comfortable now.  
- Sometimes “good enough” is *good enough*. I challenged myself to finish as fast as possible, so there are things I wish I’d explored more deeply and code that could be more efficient. But sometimes you just need to ship and move on, because no code base is ever perfect.

## 5. What I’d Do Differently

- Write more efficient redraw logic. For example, when moving the fractal with the arrow keys, I could redraw only the new columns or rows rather than every pixel.  
- Add color options—I’ve seen other `fract-ol` projects with awesome palettes, and mine is just “meh.”

## 6. Future Improvements

- Refactor repeated code.  
- Add more fractal types and customizable color schemes.

## 7. Resources & References

- [MiniLibX tutorial](https://harm-smits.github.io/42docs/libs/minilibx)  
- [Understanding Julia and Mandelbrot Sets](https://www.karlsims.com/julia.html)  
- [What’s so special about the Mandelbrot Set? – Numberphile](https://www.youtube.com/watch?v=FFftmWSzgmk)  
- [Julia Set Fractal (2D)](https://paulbourke.net/fractals/juliaset/index.html)  
- [The Julia Set by Dominic Ford](https://sciencedemos.org.uk/julia.php)
- My own tears and `gdb`  
- My friends and colleagues at 42 Lisboa

---

**Overall, `fract-ol` challenged me to design procedural graphics, optimize performance, and handle complexity. It was tough, but immensely rewarding.**

