void t_yol(int sol, int duz, int sag) 
{
  if (g_durum == 0) 
  {
    //duz gitmek icin
    if(duz == 1 && sol == 0 && sag == 0)
    {

      motorkontrol(180,180);
      while(duz == 1)
      {
        sensoroku();
        motorkontrol(sol_sh + ekhiz, sag_sh + ekhiz);
        if(!(sensors[3] < 300 && sensors[4] < 300))
        {
          motorkontrol(min_hiz, min_hiz);
          duz = 0;
          break;
        }
      }
    }

    if(duz == 0 && sol == 1 && sag == 0)
    {
      if(sensors[6] < 300 && sensors[7] > 700 && sensors[4] > 700)
      {
        motorkontrol(0,0); //salladım
        while(sol == 1)
        {
          if(sensors[3] < 300 && sensors[4] < 300) 
          {
            duz = 1;
            sol == 0;
            break;
          }
        }
      }
    }

    if(duz == 0 && sol == 0 && sag == 1)
    {
      if(sensors[1] < 300 && sensors[0] > 700 && sensors[3] > 700)
      motorkontrol(0,0); //salladim
      while (sag == 1)
      {
        if(sensors[3] < 300 && sensors[4] < 300) 
        {
          duz = 1;
          sag == 0;
          break;
        }
      }
    }

  }
}

/* //Siyah zeminde
  if (t_durum == 0) {

    if (duz_git == 1 && sol_don == 0 && sag_don == 0 && sensors[0] < 300 && sensors[1] < 300 && sensors[2] < 300 && sensors[3] < 300 && sensors[4] < 300 && sensors[5] < 300 && sensors[6] < 300 && sensors[7] < 300 || (sensors[3] < 300 && sensors[4] < 300)) {
      motorkontrol(180,180);
      while (1) {
        sensoroku();
        motorkontrol(min_hiz + ekhiz, min_hiz + ekhiz);
        if (!(sensors[0] < 300 && sensors[1] < 300 && sensors[2] < 300 && sensors[3] < 300 && sensors[4] < 300 && sensors[5] < 300 && sensors[6] < 300 && sensors[7] < 300)) {
          duz_git = 0;
          t_durum = 1;
          break;
        }
      }
    }

    if (duz_git == 0 && sol_don == 1 && sag_don == 0 && sensors[0] < 300 && sensors[1] < 300 && sensors[2] < 300 && sensors[3] < 300 && sensors[4] < 300 && sensors[5] < 300 && sensors[6] < 300 && sensors[7] < 300) {
      motorkontrol(0,0);
      while (1) {
        sensoroku();
        if (sensors[5] > 700 && sensors[6] > 700  && sensors[7] > 700) { break; }
      }
      while (1) {
        sensoroku();
          motorkontrol(0,0);
        if (sensors[7] < 300 || (sensors[6] < 300) || (sensors[7] < 300 && sensors[6] < 300)) {
          ekhiz = 5;
          sol_encoder_say = 0;
          sag_encoder_say = 0;
          ortalama_uzunluk = 0;
          sol_don = 1;
          t_durum = 1;
          break;
        }
      }
    }
    
    if (duz_git == 0 && sol_don == 0 && sag_don == 1 && sensors[0] < 300 && sensors[1] < 300 && sensors[2] < 300 && sensors[3] < 300 && sensors[4] < 300 && sensors[5] < 300 && sensors[6] < 300 && sensors[7] < 300) {
      motorkontrol(60, -30);
      while (1) {
        sensoroku();
        if (sensors[0] > 700 && sensors[1] > 700) { break; }
      }
      while (1) {
        sensoroku();
        motorkontrol(60, -10);
        if (sensors[0] < 300 || (sensors[0] < 300 && sensors[1] < 300)) {
          ekhiz = 10;
          sol_encoder_say = 0;
          sag_encoder_say = 0;
          ortalama_uzunluk = 0;
          sag_don = 1;
          t_durum = 1;
          break;
        }
      }
    }
  }
*/
