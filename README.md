# fract-ol 🐙

Explore fractals in real time! 🎉

## 📋 Quick Start

### Requirements

- macOS/Linux with X11
- MiniLibX graphics library
- GCC or Clang compiler

### Build

```bash
make
```

### Run

```bash
./fractol <set> [params] [--window <W> <H>]
```

## 🔧 Options

- `-M`, `--mandelbrot`           Render the Mandelbrot set
- `-J`, `--julia <x> <y>`        Render the Julia set (complex parameter x + yi)
- `-W`, `--window <W> <H>`       Set window size (both > 20)

## 🎮 Controls

- **ESC**       Exit program
- **Scroll**    Zoom in/out 🔍

## ✨ Examples

```bash
# Mandelbrot (default window)
./fractol -M

# Julia with z = 4.3 + 2.5i in 600×400 window
./fractol -J 4.3 2.5 --window 600 400
```

