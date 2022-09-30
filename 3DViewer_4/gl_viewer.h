#ifndef GL_VIEWER_H
#define GL_VIEWER_H
#include <QOpenGLWidget>
//#include <glu.h>

extern "C" {
    #include "parcer.h"
    #include "struct_action.h"
}

class gl_viewer: public QOpenGLWidget
{
public:
    gl_viewer(QWidget *parent = nullptr);
    struct_data model_data = {0};
    void init_test();
    GLfloat left  = 0;
    GLfloat right  = 0;
    GLfloat top  = 0;
    GLfloat botton  = 0;
    GLfloat near  = 0;
    GLfloat far  = 0;
    GLfloat red = 1, green = 0, blue = 0;

private:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
};

#endif // GL_VIEWER_H
