class Render {
public:
    vector<int> renderPixel(vector<int> screen, int x, int y) {
        // write code here
       for(int i=x;i<=y;i++){
            int a=i%8;
            int b=i/8;
            screen[b]=screen[b]|(1<<a);
             
        }
        return screen;
    }
};