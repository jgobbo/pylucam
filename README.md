# PyLucam

PyLucam is a python wrapper for the Lumenera Lucam API

Some functionality (especially errors) was copied from https://github.com/cgohlke/lucam. Only the minimum required functionality was defined in python, but additions are easy since the full library is defined in the provided header. It was tested with an Lt-C1900 camera.

## Installation

It is easiest to install with pip: `pip install pylucam`

You can also install with [uv](https://docs.astral.sh/uv/) by cloning the repo and using `uv sync`.


## Usage

Using the package should be straightforward.

```python
camera = LucamCamera()
camera.enable_fast_frames()
frame = camera.take_fast_frame_rgb()
```

If you have more than one camera, you can specify the id of the camera while initializing, `LucamCamera(CAMERA_ID)`.
