#include <SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<windows.h>

using namespace sf;
using namespace std;

#define  ROWS 12
#define  COLS 10

int swap1(int &x , int &y);
int swap2(int &x ,int &y );

int swap1(int &x ,int &y )
{
int temp=x;
x=y;
y=temp;
}

int swap2(int &x , int &y )
{
int temp=x;
x=y;
y=temp;
}


int main()
{
    // Create the main window
    RenderWindow app(VideoMode(1280, 720),"SFML window" , Style::Default );

    //Print Grid
    RectangleShape player(Vector2f(682.f,605.f));
    player.setFillColor(Color(243,84,88,100));
    player.setOutlineColor(Color(200,199,185));
    player.setOutlineThickness(0);
    player.setPosition(565,92);

    //Print Boxes
    RectangleShape print1(Vector2f(150.f,50.f));
    print1.setFillColor(Color(255,157,255));
    print1.setOutlineColor(Color(80,0,80));
    print1.setOutlineThickness(4);
    print1.setPosition(195,418);

    RectangleShape print2(Vector2f(150.f,50.f));
    print2.setFillColor(Color(170,232,232));
    print2.setOutlineColor(Color(80,0,80));
    print2.setOutlineThickness(4);
    print2.setPosition(195,518);

    RectangleShape print3(Vector2f(150.f,50.f));
    print3.setFillColor(Color(113,249,130));
    print3.setOutlineColor(Color(80,0,80));
    print3.setOutlineThickness(4);
    print3.setPosition(195,618);

    RectangleShape print4(Vector2f(180.f,50.f));
    print4.setFillColor(Color(255,157,255));
    print4.setOutlineColor(Color::Red);
    print4.setOutlineThickness(4);
    print4.setPosition(580,20);

    RectangleShape print5(Vector2f(225.f,50.f));
    print5.setFillColor(Color(255,157,255));
    print5.setOutlineColor(Color::Red);
    print5.setOutlineThickness(4);
    print5.setPosition(1015,20);

   //Print Candies
   CircleShape candy1(20.f);
   candy1.setFillColor(Color(0,206,0));
   candy1.setOutlineThickness(1.f);
   candy1.setOutlineColor(Color(250,150,100));

   CircleShape candy2(20.f,3);
   candy2.setFillColor(Color(255,0,0));
   candy2.setOutlineThickness(1.f);
   candy2.setOutlineColor(Color(250,150,100));

   CircleShape candy3(20.f,6);
   candy3.setFillColor(Color(255,255,138));
   candy3.setOutlineThickness(1.f);
   candy3.setOutlineColor(Color(250,150,100));

   CircleShape candy4(20.f,4);
   candy4.setFillColor(Color(0,0,234));
   candy4.setOutlineThickness(1.f);
   candy4.setOutlineColor(Color(250,150,100));

   CircleShape candy5(20.f,8);
   candy5.setFillColor(Color(150,50,150));
   candy5.setOutlineThickness(1.f);
   candy5.setOutlineColor(Color(250,150,100));

    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("./resources/candycrush.jpg"))
        return EXIT_FAILURE;
    Sprite sprite(texture);

    Font font;
    if(!font.loadFromFile("./resources/Candice.ttf"))
    {
        //error
    }

    //Print Text
    Text text1;
    text1.setFont(font);
    text1.setString("Play ! ");
    text1.setCharacterSize(40);
    text1.setPosition(213,413);
    text1.setFillColor(Color::Red);
    text1.setStyle(Text::Bold);

    Text text2;
    text2.setFont(font);
    text2.setString("Save ! ");
    text2.setCharacterSize(40);
    text2.setPosition(211,513);
    text2.setFillColor(Color::Red);
    text2.setStyle(Text::Bold);

    Text text3;
    text3.setFont(font);
    text3.setString("Load ! ");
    text3.setCharacterSize(40);
    text3.setPosition(211,613);
    text3.setFillColor(Color::Red);
    text3.setStyle(Text::Bold);

    Text text4;
    text4.setFont(font);
    text4.setString("Score:00");
    text4.setCharacterSize(40);
    text4.setPosition(582,18);
    text4.setFillColor(Color::Red);
    text4.setStyle(Text::Bold);

    Text text5;
    text5.setFont(font);
    text5.setString("Moves Left:00");
    text5.setCharacterSize(30);
    text5.setPosition(1020,24);
    text5.setFillColor(Color::Red);
    text5.setStyle(Text::Bold);


    int candyArray[ROWS][COLS];
    srand(time(0));

    for(int i=0 ;i<ROWS ; i++){
       for(int j=0; j<COLS ; j++){

        candyArray[i][j]=rand()%5;

       }
    }

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
           int x1,y1,x2,y2;
        if(event.type == Event::MouseButtonPressed)
          {
            if(event.mouseButton.button == Mouse::Left)
                {
                x1=event.mouseButton.x;
                y1=event.mouseButton.y;
                }
                cout<<"Button Pressed : "<<x1<<" , " <<y1<<endl;
          }
          if(event.type == Event::MouseButtonReleased)
          {
            if(event.mouseButton.button == Mouse::Left)
                {
                x2=event.mouseButton.x;
                y2=event.mouseButton.y;
                }
                cout<<"Button Released : "<<x2 <<" , " <<y2<<endl;

               int cod_1 = (x1-570)/55;
               int cod_2 =(y1-100)/50;


if  (((x1 >= 570 ) && (x1 <= 1250 ) && (y1 >= 100) && (y1 <= 700) ))
 {
    if(swap1(x1,x2) > swap1(y1,y2))
     {
        if(x1<x2)
           {
              swap2(candyArray[cod_2][cod_1],candyArray[cod_2][cod_1+1]);
           }
        else if(x1>x2)
           {
             swap2(candyArray[cod_2][cod_1],candyArray[cod_2][cod_1-1]);
           }
     }

    else if(swap1(x1,x2) < swap1(y1,y2))
     {
      if(y1<y2)
           {
             swap2(candyArray[cod_2][cod_1],candyArray[cod_2+1][cod_1]);
           }
        else if(y1>y2)
           {
             swap2(candyArray[cod_2][cod_1],candyArray[cod_2-1][cod_1]);
           }
     }
 }
          }
    }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);
        app.draw(player);
        app.draw(print1);
        app.draw(print2);
        app.draw(print3);
        app.draw(print4);
        app.draw(print5);
        app.draw(text1);
        app.draw(text2);
        app.draw(text3);
        app.draw(text4);
        app.draw(text5);

int x=100;
int y=100;
for(int i=0 ;i<ROWS ; i++){
    int x=570;
   for(int j=0 ;  j<COLS ; j++){

    if(candyArray[i][j]==0)
      {
       candy1.setPosition(x,y);
       app.draw(candy1);
      }
     else if(candyArray[i][j]==1)
      {
       candy2.setPosition(x,y);
       app.draw(candy2);
      }

     else if(candyArray[i][j]==2)
      {
       candy3.setPosition(x,y);
       app.draw(candy3);
      }
     else if(candyArray[i][j]==3)
      {
       candy4.setPosition(x,y);
       app.draw(candy4);
      }
     else if(candyArray[i][j]==4)
      {
       candy5.setPosition(x,y);
       app.draw(candy5);
      }
         x=x+70;
  }
         y=y+50;
}

        // Update the window
        app.display();
}

    return EXIT_SUCCESS;
}
