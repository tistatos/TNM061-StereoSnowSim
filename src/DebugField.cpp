#include "DebugField.h"

DebugField::DebugField(sgct::Engine* engine)
{
	mEngine = engine;
	mMatrixLocation = -1;
	mShowDebug = true; // default
}

void DebugField::init()
{
    static const GLfloat arrowBufferData[] =
    {
        0.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    // glGenVertexArrays(1, &linesArray);
    // glBindVertexArray(linesArray);

    // glGenBuffers(1, &arrayVB);
    // glBindBuffer(GL_ARRAY_BUFFER, arrayVB);

    // glBufferData(GL_ARRAY_BUFFER, sizeof(arrowBufferData),
    //              arrowBufferData, GL_STATIC_DRAW);

    glVertexAttribPointer(
                0,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                reinterpret_cast<void*>(0)
        );

    glEnableVertexAttribArray(0);

    //Create shader
    sgct::ShaderManager::instance()->addShaderProgram("arrow", "arrow.vert", "arrow.frag");

    mMatrixLocation = sgct::ShaderManager::instance()->getShaderProgram("arrow").getUniformLocation( "MVP" );
    mTransformLocation = sgct::ShaderManager::instance()->getShaderProgram("arrow").getUniformLocation( "P" );

    //Unbind shader
    sgct::ShaderManager::instance()->unBindShaderProgram();

    // glDrawArrays(GL_LINES);
}

void DebugField::draw(Field &f)
{
	std::cout << "Drawing field" << std::endl;
	f.printInfo();
}
