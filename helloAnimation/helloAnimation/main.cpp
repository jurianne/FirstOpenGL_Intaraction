//
//  main.cpp
//  helloAnimation
//
//  Created by Juri Fujii on 2018/04/24.
//  Copyright © 2018 jf. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>

float r = 0.7; //radius　半径
GLenum mode = GL_LINES; //描画するモード
float red = 0.0;
float blue  =0.0;
int count = 0;

float divNum = 100.0;


void display(){ //displayが関数の名前
    //draw something
    glClear(GL_COLOR_BUFFER_BIT); // 背景を描く．buffer=メモリーの1個の領域．
    //draw rectangle
    glColor3f(red,blue,1.0); //マウスで色を変える//色は0~1で指定
    
    glBegin(mode); // beginで始まったら絶対endで終わる．頂点をその間に指定する
    
    //1個前の値を入れる箱
    float prev_x = 0.0;
    float prev_y = 0.0;
    //for ( float t =0.0; t < 2*M_PI + 0.05; t += 0.05){//2M_PIで１周 M_PIは円3.14 t = theta 角度
    for(float f = 0.0; f < divNum + 1.0; f += 1.0){
        //三角関数
        //float x = r * cos(t);
        //float y = r * sin(t);
        
        float x = r * cos(2*M_PI * (f/divNum));
        float y = r * sin((2*M_PI * (f/divNum)));
        
        if(f != 0.0){
            glVertex3f(prev_x, prev_y,0.0);//1個前の座標と今の座標をつなぐ
            glVertex3f(x,y,0.0);//1個前の座標地をどこに保存するのか？
            
        }
        prev_x = x;
        prev_y = y;
    }
    
    
    
    glEnd();
    glFlush(); //絵かいて！ //データを実行
    glutPostRedisplay(); //強制再描画．
}

void keyboard(unsigned char key, int x, int y){ //パラメータ　一つ目は文字じゃなきゃいけない
    if(key == 'q'){
        exit(0);//プログラムを終了する quit program
        
    }else if(key == '1'){//そうじゃなくてもし〜
        mode = GL_POINTS;
        count++;
    }else if(key == '2' ){
        mode = GL_LINES;
        count++;
    }else if(key == '3'){
        mode = GL_POLYGON;
        count++;
    }
    
    std::cout << count << "\n"; //デバック．コンソールに数値を表示
}

void mouse(int x, int y){ //x座標 y座標
    red = (float)x/500.0; //型変換(キャスト)
    blue = (float)y / 500.0;
    divNum =(float)y/50 +1;
    //r =(float)x/500.0;
    
    glutPostRedisplay();
    std::cout << red << "\n"; //デバック．コンソールに数値を表示
    
}

int main(int argc,  char * argv[]) {
    glutInit(&argc, argv); //initialize初期化
    glutInitDisplayMode(GLUT_RGB); //Display Mode
    glutInitWindowSize(500,500); //window size
    glutCreateWindow("hello graphics"); // Create Window　"ウィンドウ名"
    glutDisplayFunc(display); //上の#13のdisplayという関数につながるので名前は一致させること
    
    //キーボード入力を可能にする
    glutKeyboardFunc(keyboard);//キーボード入力を許可
    glutMotionFunc(mouse); // ()の中はその機能を諸々入れる関数名を入れとく
    
    
    
    //ここで指定した関数はmainの上に書かないと実行できない
    glClearColor(0.0,0.0,0.0,0.0); //Clear Color 背景の色 RGB + アルファ　光の３原色
    glutMainLoop();
    
    
    
    return 0;
}

