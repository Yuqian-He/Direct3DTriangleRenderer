/*
The role of the vertex shader is to 
process the input data of each vertex (such as the vertex position and color) and pass it to the next stage of the pipeline.
*/

// vertex_shader.hlsl
struct VSInput {
    float3 position : POSITION;
    float4 color : COLOR;
};

struct PSInput {
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

PSInput main(VSInput input) {
    PSInput output;
    output.position = float4(input.position, 1.0f);
    output.color = input.color;
    return output;
}
