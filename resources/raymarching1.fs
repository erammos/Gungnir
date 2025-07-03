#version 330 core

// 'out' is the keyword used in modern GLSL to declare an output variable.
// This variable will hold the final color of the pixel.
out vec4 FragColor;

// Uniforms are global variables passed from the host application (e.g., C++).
// u_resolution: The resolution of the viewport (width, height)
// u_time: A continuously increasing value for animation
uniform vec2 u_resolution;
uniform float u_time;

// Helper function to convert HSV (Hue, Saturation, Value) color to RGB.
// This is a common utility in shader art for vibrant color schemes.
vec3 hsv(float h, float s, float v) {
    vec4 t = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(vec3(h) + t.xyz) * 6.0 - vec3(t.w));
    return v * mix(vec3(t.x), clamp(p - vec3(t.x), 0.0, 1.0), s);
}

// The main function that runs for every single pixel on the screen.
// Its final output is the color of that pixel, written to 'FragColor'.
void main() {
    // Initialize a temporary color variable.
    vec4 o = vec4(0.0);

    // Set up the initial ray direction for raymarching.
    // It's calculated based on the pixel's position (gl_FragCoord)
    // to create a perspective effect. gl_FragCoord is a built-in input.
    vec3 d = vec3((gl_FragCoord.xy - 0.5 * u_resolution.xy) / u_resolution.y, 0.8);

    // Initialize variables for the raymarching loop
    float e = 0.0; // Estimated distance to the surface
    float g = 0.0; // A variable for accumulation, not directly used in final color
    float R = 1.0; // Represents the length/distance of the ray
    vec3 q = vec3(0.0, 0.0, -1.0); // The origin of the ray
    vec3 p; // A temporary position vector

    // The main raymarching loop.
    for(float i = 0.0; i < 99.0; i++){
        float s = 3.0;
        p = q;
        p += d * e * R * 0.25;

        g += p.y / s;
        R = length(p);

        // The core of the fractal generation.
        p = vec3(log2(R) + u_time * 0.2, exp2(mod(-p.z, s) / R) - 0.23, p.x);

        e = p.y;
        p.y -= 1.0;

        // Inner loop refines the distance estimate to the surface.
        for(float j = 0.0; j < 10.0; j++){
            e += -abs(dot(sin(p.xz * s), cos(p.zy * s)) / s * 0.5);
            s *= 2.0;
            if (s > 6000.0) break;
        }

        // Accumulate color.
        o.rgb += hsv(p.y, q.y, min(e * i, 0.01));

        // Update the main ray position for the next iteration.
        q += d * e * R * 0.25;
    }

    // Assign the final calculated color to the output variable.
    FragColor = vec4(o.rgb, 1.0);
}
