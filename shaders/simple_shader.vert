#version 450

vec2 positions[3] = vec2[] (
        vec2(0.0, -0.5),
        vec2(0.5, 0.5),
        vec2(-0.5, 0.5)
        );

void main()
{
    //gl_Position is where the output is pushed.
    //Notice how vec4 has first element coming from index vertex buffer.
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
}
