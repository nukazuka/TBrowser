void execution_test()
{

  TF1* f = new TF1( "func", "pol1", 0, 1 );
  f->SetParameters( 0.5, 0.5 );
  f->Draw( "L SAME" );
}
