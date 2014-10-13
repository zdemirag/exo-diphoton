#include "TMath.h"
void dipho_reso() {

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
  tdrStyle->SetStatFontSize(0.045);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.19);

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

 
  //Reso
  const Int_t n = 31;
  Float_t mass[n]    = {50,55,60,65,70,75,80,85,90,95,100,105,110,120,130,140,150,200,300,500,550,600,650,700,750,800,900,1000,1500,2000,3000};
  
  Float_t width[n]   = {0.023975050376,0.022135476257,0.0213080767407,0.020100100662,0.018156569571,0.0169025238605,0.0167879992275,0.0170078001491,0.0152132827839,0.0156393183989,0.0135177355154,0.0145416921603,0.0136804580674,0.0135591683208,0.0133039303116,0.00981053821843,0.0111482305745,0.0100276955686,0.00867590858095,0.00724825179662,0.00719834173713,0.00732091092459,0.0071679612701,0.00721164859289,0.00766695187911,0.00763696727892,0.0075383693261,0.00779037291578,0.00856710991652,0.0106204318668};
 
  Float_t ey[n]      = {0.00037316475311,0.000338199879666,0.000317923986043,0.000325468163902,0.00035087377305,0.000417844918747,0.000492807129423,0.000471398292383,0.000478857131492,0.000604183373252,0.000684934625367,0.000868587363943,0.000529756582525,0.000601595734525,0.000592621993953,0.000814665031062,0.000445493106255,0.000481610397404,0.000829389205341,8.53577076125e-05,7.90630664167e-05,8.30566597111e-05,9.75379357628e-05,0.000107939024254,0.000115583921297,0.000101356307162,0.000132196456452,0.0001257709101,0.00030537448294,0.000698576982532};

  Float_t ex[n]      = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};

  Float_t width_new[n];
  Float_t ey_new[n];

  for(int i =0; i < n; i++){

    cout << "width[i]: " <<  width[i] <<endl;
    width_new[i] = TMath::Sqrt( (width[i]**2) + (0.01**2)) * 100;
    ey_new[i] = ey[i] *100;

  }


 

 


  TCanvas *c1 = new TCanvas("c1","c1",680,600);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();

  TCanvas *c1 = new TCanvas("c1","c1",680,600);
  c1->cd();
  c1->SetGridx();
  c1->SetGridy();
  
  
  TGraphErrors *gr = new TGraphErrors(n,mass,width_new,ex,ey_new);
  gr->GetXaxis()->SetTitle("M#gamma#gamma [GeV]");
  gr->SetTitle("EB-EB");
  gr->GetYaxis()->SetTitle("#sqrt{ #sigma_{fit}^{2} + #sigma_{extra}^{2} } %" );
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.2);
  gr->Draw("AP");
 



  TF1 *f = new TF1("f","TMath::Sqrt([0]**2 / x**2 + [1]**2/x + [2]**2)",0,3000);
  //TF1 *f = new TF1("f","TMath::Sqrt([0]**2 / x**2 + [1]**2/x )",0,3000);
  f->SetLineWidth(2);
  f->SetLineColor(2);
  gr->Fit(f,"MR");
  

}
