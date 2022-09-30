#include "gl_viewer.h"
#include <iostream>




gl_viewer::gl_viewer(QWidget *parent) : QOpenGLWidget(parent)
{

}


void gl_viewer::initializeGL() {

      glEnable(GL_DEPTH_TEST);
       //glMatrixMode(GL_PROJECTION);
       //glLoadIdentity;
      // glOrtho(-1.0, 1.0, -1.0, 1.0, 0.1, 10.0);

}

void gl_viewer::resizeGL(int w, int h){

}

void gl_viewer::paintGL() {


    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);


      //двуточечная центральная проекция
     // glViewPort(0,0,clientwidth, clientheight);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity;
      glFrustum(left, right, botton, top, near, far);
//std::cout <<  left << " :: " << right << " :: " << botton << " :: " << top  << " :: " << near << " :: " << far << std::endl;
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity;
     // glTranslatef(0,0,-3);
      glRotatef(45, 1,1,0);

    if (model_data.count_of_v != 0) {
   //   glMatrixMode(GL_MODELVIEW);
     //   glLoadIdentity;
      //  glEnableClientState(GL_VERTEX_ARRAY);
          std::cout << "20 test";
        // Отрисовываем полигоны
      for (unsigned int i = 0; i < model_data.count_of_f; i++) {


          int num_point = 0;
            glBegin(GL_LINE_LOOP);
                glColor3d(red, green, blue);

                //std::cout << "81\n" << std::endl;

                for (int ki = 0; ki < model_data.polygons[i].numbers_of_vertexes_in_facets; ki++) {

                 num_point = model_data.polygons[i].vertexes[ki];
                  std::cout << "51: " << num_point << ":   ";
                 double x = 0, y = 0, z = 0;
                 x =  model_data.matrix_3d.matrix[(num_point-1)*3+0];
                 y =  model_data.matrix_3d.matrix[(num_point-1)*3+1];
                 z =  model_data.matrix_3d.matrix[(num_point-1)*3+2];
                std::cout << x <<" : " << y << " : " << z << std::endl;
               //std::cout << ki << ": "<< model_data.matrix_3d.matrix[i*3+ki] << std::endl;
               glVertex3d(x, y, z);
               num_point = 0;

            }
                 std::cout << std::endl;
               //  glRotatef(30.0, 1.0, 0.0, 1.0);
             glEnd();
      }
    }
}

   // glDrawElements(GL_LINES, 6, GL_DOUBLE, Coord);
    /*
    glDrawArrays(GL_LINES,
                 0, // начало
                 2); // количество вершин
    glDisableClientState(GL_VERTEX_ARRAY);
    */


void gl_viewer::init_test() {
    char file_name[256] = "/Users/svetislavdobromirov/Downloads/cubes.obj";
    start_parcer(&model_data, file_name);
      std::cout << "65 test";
    show();
}
