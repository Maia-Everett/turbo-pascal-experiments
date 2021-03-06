program fire;
uses unit3d,crt;

var
  i,j,apu,a,asu,b,bsu:integer;
  virtu:word;
  c,axa,yy:real;
  apuruutu:array[0..319,0..199]of byte;

procedure sumenna;
label Loop;
begin
  asm
    les di, virscr
    add di, 320
    mov cx, 63360
    xor ax, ax
    xor bx, bx
  end;
  Loop:
  asm
    mov al, [es:di-1]
    mov bl, [es:di+1]
    add ax, bx
    mov bl, [es:di-320]
    add ax, bx
    mov bl, [es:di+320]
    add ax, bx
    shr ax, 2
    stosb
    loop Loop
  end;
end;

procedure piirra(alkux:integer;alkuy:integer;loppux:integer;loppuy:integer;askelet:integer;koko:integer);
var
  axvali,yyvali:real;
  h,hop,op:integer;
  x,y:real;

begin
  axvali:=(loppux-alkux)/askelet;
  yyvali:=(loppuy-alkuy)/askelet;
  x:=alkux;
  y:=alkuy;
  for op:=1 to askelet do
  begin
    for h:=round(y-koko) to round(y+koko) do
      for hop:=round(x-koko) to round(x+koko) do putpixel(hop,h,255,vaddr);
    x:=x+axvali;
    y:=y+yyvali;
  c:=c+0.02;
  axa:=sin(c)*cos(c*0.52)*140;
  yy:=cos(c*0.61)*sin(c*0.67)*80;
  for i:=158+round(-axa) to 162+round(-axa) do
  begin
    for j:=98+round(-yy) to 102+round(-yy) do putpixel(i,j,155,vaddr);
  end;
  for i:=158+round(axa) to 162+round(axa) do
  begin
    for j:=98+round(yy) to 102+round(yy) do putpixel(i,j,155,vaddr);
  end;
    flip;
    sumenna;
  end;
end;

procedure play;
begin
  piirra(30,30,110,30,40,5);
  piirra(70,30,70,140,30,5);
  piirra(130,110,160,90,20,5);
  piirra(160,90,140,70,20,5);
  piirra(140,70,120,90,20,5);
  piirra(120,90,140,140,20,5);
  piirra(140,140,170,130,20,5);
  piirra(200,140,200,70,20,5);
  piirra(200,70,230,80,20,5);
  piirra(230,80,210,100,20,5);
  piirra(210,100,230,140,20,5);
  piirra(270,70,290,100,20,5);
  piirra(290,100,270,140,20,5);
  piirra(270,140,250,100,20,5);
  piirra(250,100,270,70,20,5);
  piirra(20,170,300,170,25,5);
  piirra(300,170,20,170,25,5);


{  if (a+asu<-139)or(a+asu>159) then asu:=-asu;
  a:=a+asu;
  if (b+bsu<-89)or(b+bsu>89) then bsu:=-bsu;
  b:=b+bsu;}

end;

begin
  setmcga;
  asu:=4;
  a:=0;
  bsu:=3;
  b:=0;
  setupvirtual;
  cls(0,vaddr);
  for apu:=0 to 63 do pal(apu,round(apu),0,0);
  for apu:=64 to 127 do pal(apu,63,round(apu),0);
  for apu:=128 to 191 do pal(apu,63,63,round(apu));
  for apu:=192 to 255 do pal(apu,63,63,63);
  randomize;
  repeat play;
  until keypressed;
  settext;
  shutdown;
end.