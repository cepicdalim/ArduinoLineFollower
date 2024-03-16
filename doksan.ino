//ayarlancak
void don() {
  if (don_durum == 0) 
  {
     //duz
    if(sensors[0] < 300 && sensors[1] < 300 && sensors[2] < 300 && sensors[3] < 300 && sensors[4] < 300 && sensors[5] < 300 && sensors[6] < 300 && sensors[7] < 300)
    {
      t_yol(0,1,0);
    }
    //sag
    if (sensors[0] < 300 && sensors[1] < 300 && sensors[2] > 700 && sensors[3] > 700 && sensors[6] < 700 && sensors[7] < 700) 
    {
      t_yol(0, 0, 1);      
    }
   
    //sol
   if (sensors[0] < 300 && sensors[0] > 700 && sensors[1] > 700 && sensors[2] > 700 && sensors[3] > 700 && sensors[4] > 700 && sensors[5] > 700 && sensors[6] > 700 && sensors[7] < 300) 
    {
      t_yol(1, 0, 0);   
    }

  }
  don_durum = 0;
}
