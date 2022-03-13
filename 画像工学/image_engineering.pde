PImage f, g;   

void setup() {
  int   x, y;  
  float a,fg=0,ff=0,gg=0,ssd=0,ncc= 0;  
  
  f = loadImage("image1.jpg");
  g = loadImage("image2.jpg");  
  f.filter(GRAY);
  g.filter(GRAY);
  surface.setSize(f.width*2, f.height);   
//以下　ラスター走査を用い画像の読み込み
  for (y = 0; y < f.height; y++) {  
    for (x = 0; x < f.width; x++) {
      //ベクトルの長さにより1画素ずつの明るさの差異を計算
      a = red(f.get(x, y)) - red(g.get(x, y));  
      ssd += a*a; 
      
      fg += red(f.get(x, y)) * red(g.get(x, y));  
      ff += red(f.get(x, y)) * red(f.get(x, y));
      gg += red(g.get(x, y)) * red(g.get(x, y));
    }
  }    
  //ベクトルの角度を計算し、画像の差異を計算
  ncc=fg/sqrt(ff*gg);
  
  println("SSD =", ssd);  
  println("NCC =", ncc);  
}
//処理後の画像を表示
void draw() {
  image(f, 0, 0);  
  image(g, f.width, 0);  
}
