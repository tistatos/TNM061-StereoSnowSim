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

// FIXME
// i crash
// segmentation fauls osv
void DebugField::draw(Field* f)
{
	if(mShowDebug)
	{
		std::cout << "[POINTER] Drawing field" << std::endl;
		f->printInfo();
	}
}
void DebugField::draw(Field& f)
{
	if(mShowDebug)
	{
		std::cout << "[REF] Drawing field" << std::endl;
		f.printInfo();
	}
}

void DebugField::draw(ParticleSystem* p)
{
	if(mShowDebug)
	{
		for(std::vector<Field*>::iterator f = p->getFields().begin(); f != p->getFields().end(); ++f)
		{
			draw((*f));
		}
	}
}
