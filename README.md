Python wrapper for Lumenera Lucam API

Some functionality (especially errors) was copied from https://github.com/cgohlke/lucam. Only the minimum required functionality was defined in python, but additions are easy since the full library is defined in the provided header. It was tested with an Lt-C1900 camera.

<h5>Basic Example</h5>

    camera = LucamCamera()
    camera.enable_fast_frames()
    frame = camera.take_fast_frame_rgb()
