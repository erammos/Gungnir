#version 330 core

// The output color of the fragment.
out vec4 FragColor;

void main()
{
    // Set the output color to a solid orange (Red=1.0, Green=0.5, Blue=0.2, Alpha=1.0).
    FragColor = vec4(1.0, 1.0, 0.2, 1.0);
}