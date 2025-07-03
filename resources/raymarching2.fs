#version 330 core

uniform vec2 iResolution;  // (width, height)
uniform float iTime;       // seconds since start

in vec2 vUV;               // Passed from vertex shader (normalized 0.0–1.0)
out vec4 FragColor;

// HSV to RGB function
vec3 hsv(float h, float s, float v) {
    vec3 c = vec3(h, s, v);
    vec4 K = vec4(1.0, 2.0/3.0, 1.0/3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main() {
    // Convert normalized UV to pixel coordinates like ShaderToy
    vec2 fragCoord = vUV * iResolution;

    float i = 0.0, e = 0.0, g = 0.0, R = 0.0, s;
    vec3 q = vec3(0.0), p = vec3(0.0);

    vec2 r = iResolution;
    vec3 d = vec3((fragCoord.yx - 0.5 * r) / r, 0.8); // ray dir

    vec3 color = vec3(0.0);

    q.zy -= 1.0;

    for(i = 0.0; i < 99.0; i++) {
        e += i / 9e9;
        color += hsv(p.y, q.y, min(e * i, 0.01));
        s = 3.0;
        p = q += d * e * R * 0.25;
        g += p.y / s;

        R = length(p);
        p = vec3(
            log2(R) + iTime * 0.2,
            exp2(mod(-p.z, s) / R) - 0.23,
            p.y
        );

        e = --p.y;
        for(s = 3.0; s < 6000.0; s += s) {
            e += -abs(dot(sin(p.xz * s), cos(p.zy * s)) / s * 0.5);
        }
    }

    FragColor = vec4(color, 1.0);
}
