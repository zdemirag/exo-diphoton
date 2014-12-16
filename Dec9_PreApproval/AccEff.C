void AccEff() {

  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);
  
  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  // For the histo:
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  tdrStyle->SetEndErrorSize(2);
  tdrStyle->SetErrorX(0.);

  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat("emr"); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);

  // Margins:
  tdrStyle->SetPadTopMargin(0.07);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.13);
  tdrStyle->SetPadRightMargin(0.05);

  // For the Global title:
  //tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(35);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.045);
  tdrStyle->SetTitleX(0.15); // Set the position of the title box
  tdrStyle->SetTitleBorderSize(0);

  // For the axis titles:
  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.05, "XYZ");
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);
  
  // For the axis labels:
  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.03, "XYZ");

  // For the axis:
  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  // Postscript options:
  tdrStyle->SetPaperSize(20.,20.);
  tdrStyle->SetPalette(1);
  
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  tdrStyle->SetNumberContours(NCont);
  
  gROOT -> ForceStyle();

  tdrStyle->cd();




  
  //Acceptance * Efficiency:
  const Int_t n = 9;
  Float_t mass[n]    = {750,1000,1250,1500,1750,2000,2250,2500,3000};
  // Float_t AccxEff[n] = {0.2377990484,0.2913043499,0.3370562494,0.3762954175,0.4098855555,0.440413475,0.4653176963,0.4685668647,0.4833472967 }
 // Float_t AccxEff[n] = {0.331938,0.379936,0.420901,0.460234,0.500914,0.528017,0.576227};
 // Float_t ey[n]      = {0.00297353,0.00306546,0.00311809,0.00314066,0.0031517,0.00315378,0.00312095 };

  Float_t AccxEff[n] = {0.4125598073,0.466852814,0.5118468404,0.5472701788,0.589081347,0.6204102635,0.6408445239,0.6485947967,0.6592876315};

  Float_t ex[n]      = {0,0,0,0,0,0,0,0,0};

  Float_t ey[n]      = {0,0,0,0,0,0,0,0,0};
  Float_t ex[n]      = {0,0,0,0,0,0,0,0,0};


 for(int i = 0; i<n; i++){
   ey[i] = TMath::Sqrt(AccxEff[i]*(1-AccxEff[i])/2500);
   std::cout <<ey[i] <<std::endl;
 }

  
  TCanvas *c1 = new TCanvas("c1","c1",680,600);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();


  /*
   TGraph *graph = new TGraph(9);
   
   graph->SetPoint(0,750,0.4125598073);
   graph->SetPoint(1,1000,0.466852814);
   graph->SetPoint(2,1250,0.5118468404);
   graph->SetPoint(3,1500,0.5472701788);
   graph->SetPoint(4,1750,0.589081347);
   graph->SetPoint(5,2000,0.6204102635);
   graph->SetPoint(6,2250,0.6408445239);
   graph->SetPoint(7,2500,0.6485947967);
   graph->SetPoint(8,3000,0.6592876315);
  */
  //TGraphErrors *gr = new TGraphErrors(n,mass,width,ex,ey);
  TGraphErrors *graph = new TGraphErrors(n,mass,AccxEff,ex,ey);
  graph->SetTitle("RS Graviton Signal");
  graph->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  graph->GetYaxis()->SetTitle("Acceptance * Efficiency");
  //gr->GetYaxis()->SetTitle("Signal Width (CB)");
  graph->SetMarkerColor(4);
  graph->SetMarkerStyle(20);
  graph->SetMarkerSize(1.2);
  graph->Draw("AP");

  
  TF1 *erf1 = new TF1("erf1", "0.5*[2]*(1+TMath::Erf( (x-[0]) / ([1]*sqrt(2)) ) )",0.0,1000.0);
  erf1->SetParameter(0,0);
  erf1->SetParameter(1,1000);
  erf1->SetParameter(2,0.65);
  erf1->SetParLimits(2,0.0,1.0);
  erf1->SetLineColor(2);
  erf1->SetLineWidth(2);
  graph->Fit(erf1);

  //TF1 *fexp = new TF1("fexp","expo",200,3000);
  //fexp->SetLineWidth(2);
  //fexp->SetLineColor(2);
  //h->Fit(fexp,"RW");



}
