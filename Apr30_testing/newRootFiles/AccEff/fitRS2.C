void fitRS2(int mass=2000, int coupling=1){

  using namespace std;
  using namespace RooFit;
  
  gSystem->Load("libRooFit.so");
  gSystem->Load("libRooFitCore.so");

  gROOT->SetStyle("Plain");

  float mass_min = mass-1000;
  float mass_max = mass+500;
  
  if (mass==750 && coupling==1) {
    mass_min=600;
    mass_max=850;
  } else if (mass==1000 && coupling==1) {
    mass_min=800;
    mass_max=1150;
  } else if (mass==1250 && coupling==1) {
    mass_min=1000;
    mass_max=1400;
  } else if (mass==1500 && coupling==1) {
    mass_min=1300;
    mass_max=1650;
  } else if (mass==1750 && coupling==1) {
    mass_min=1500;
    mass_max=1900;
  } else if (mass==2000 && coupling==1) {
    mass_min=1400;
    mass_max=2400;
  } else if (mass==3000 && coupling==1) {
    mass_min=2400;
    mass_max=3300;
  } else if (mass==1750 && coupling==5) {
    mass_min=1300;
    mass_max=2000;
  } else if (mass==2000 && coupling==5) {
    mass_min=1500;
    mass_max=2300;
  } else if (mass==2500 && coupling==5) {
    mass_min=1500;
    mass_max=3000;
  } else if (mass==2750 && coupling==5) {
    mass_min=2000;
    mass_max=3000;
  } else if (mass==3000 && coupling==5) {
    mass_min=2000;
    mass_max=3600;
  } else if (mass==1500 && coupling==10) {
    mass_min=1000;
    mass_max=2000;
  } else if (mass==2250 && coupling==10) {
    mass_min=1400;
    mass_max=2600;
  } else if (mass==2500 && coupling==10) {
    mass_min=1500;
    mass_max=3000;
  } else if (mass==2750 && coupling==10) {
    mass_min=2000;
    mass_max=3300;
  } else if (mass==3000 && coupling==10) {
    mass_min=1500;
    mass_max=3800;
  } else if (mass==3250 && coupling==10) {
    mass_min=2000;
    mass_max=4000;
  } else if (mass==3500 && coupling==10) {
    mass_min=2500;
    mass_max=4000;
  }
  
  if (mass_min<0) mass_min=0;
  
  std::cout << "MASS " << mass << " " << mass_min << " " << mass_max << std::endl;
  std::cout << "COUPLING " << coupling << std::endl;

  char name[300];
  
//   if (coupling==10) {
//     sprintf(name,"diphoton_tree_RSGravToGG_kMpl-01_M-%i_TuneZ2star_8TeV-pythia_merged.root",mass);
//   } else if (coupling==5) {
//     sprintf(name,"diphoton_tree_RSGravToGG_kMpl-005_M-%i_TuneZ2star_8TeV-pythia_merged.root",mass);
//   } else if (coupling==1) {
//     sprintf(name,"diphoton_tree_RSGravToGG_kMpl-001_M-%i_TuneZ2star_8TeV-pythia_merged.root",mass);
//   } else {
//     std::cout << "WRONG COUPLING VALUE!" << std::endl;
//     return;
//   }

//   TFile* f = new TFile(name);
//   //   std::cout << f << std::endl;
  
//   if (!f || !f->IsOpen()) {
//     cout << "File does not exist!" << endl;
//     return;
//   }
  
//   TTree* t = (TTree*)f->Get("tDiphoton");
//   t->Print();

//   RooRealVar minv("minv","M_{#gamma #gamma}",mass_min,mass_max,"GeV") ;
//   RooRealVar weight("weight","weight",0.,10.);

//   //  RooDataSet data("data_signal", "data_signal",RooArgList(mass,weight),RooFit::WeightVar("weight"));  
//   RooDataSet data("data", "data_signal",t,RooArgList(minv,weight),0,"weight");  
  
//  data.Print("v");
  
  if (coupling==10) {
    sprintf(name,"istograms_diphoton_tree_RSGravToGG_kMpl-01_M-%i_TuneZ2star_8TeV-pythia_merged.root",mass,mass);
  } else if (coupling==5) {
    sprintf(name,"histograms_diphoton_tree_RSGravToGG_kMpl-005_M-%i_TuneZ2star_8TeV-pythia_merged.root",mass,mass);
  } else if (coupling==1) {
    sprintf(name,"histograms_diphoton_tree_RSGravToGG_kMpl-001_M-%i_TuneZ2star_8TeV-pythia_merged.root",mass,mass);
  } else {
    std::cout << "WRONG COUPLING VALUE!" << std::endl;
    return;
  }

  std::string fileName(name);
  std::string fileLocation = "/afs/cern.ch/user/s/scooper/work/public/4Zeynep/";
  TFile* f = new TFile((fileLocation+fileName).c_str());
  //   std::cout << f << std::endl;
  
  if (!f || !f->IsOpen()) {
    cout << "File does not exist!" << endl;
    return;
  }

  TH1F* histo = (TH1F*)f->Get("h_Diphoton_Minv_FineBinning");
  TH1F* histoOrig = (TH1F*)histo->Clone();
  histo->Rebin(5);
  RooRealVar minv("minv","M_{#gamma #gamma}",mass_min,mass_max,"GeV") ;

  RooDataHist data("data","data_signal",RooArgList(minv),histo);  
  data.Print("v");

  RooPlot* mframe = minv.frame();
  data.plotOn(mframe);

  RooRealVar mean("meanCB","mean of gaussian",3450.,0.,4000.) ; 
  RooRealVar sigma("sigmaCB","width of gaussian",60.,0.,100.) ; 
  RooRealVar alpha("alphaCB","gaussian tail",1.8,0,10.0) ; 
  RooRealVar n_var("n_varCB","normalization",0.9,.0,10.0);
  
  //mean.Print();
  //sigma.Print();
  //alpha.Print();
  //n_var.Print();
  
  RooCBShape crystalball("crystalball","Crystal Ball PDF",minv,mean,sigma,alpha,n_var);
  RooRealVar bwMean("bwMean","bwMean",2000.0,0,4000);
  RooRealVar bwSigma("bwSigma","bwSigma",15,0.1,50);
  if (mass==1000 && coupling==1)
  {
    bwMean.setVal(1000); bwMean.setRange(900,1100);
    bwSigma.setVal(11); bwSigma.setRange(2,25);
    // CB
    mean.setVal(1.2); mean.setRange(-25,25);
    sigma.setVal(15); sigma.setRange(0.1,20);
    alpha.setVal(1.5); alpha.setRange(-5.0,5.0);
    n_var.setVal(2.4); n_var.setRange(0.1,10.0);    
  }
  if (mass==1250 && coupling==1)
  {
    bwMean.setVal(1250); bwMean.setRange(1150,1350);
    bwSigma.setVal(11); bwSigma.setRange(2,25);
    // CB
    mean.setVal(1.2); mean.setRange(-25,25);
    sigma.setVal(15); sigma.setRange(0.1,20);
    alpha.setVal(1.5); alpha.setRange(-5.0,5.0);
    n_var.setVal(2.4); n_var.setRange(0.1,10.0);    
  }
  if (mass==2000 && coupling==1)
  {
    bwMean.setVal(2000); bwMean.setRange(1900,2100);
    bwSigma.setVal(11); bwSigma.setRange(2,25);
    // CB
    mean.setVal(1.2); mean.setRange(-25,25);
    sigma.setVal(15); sigma.setRange(0.1,20);
    alpha.setVal(1.5); alpha.setRange(-5.0,5.0);
    n_var.setVal(2.4); n_var.setRange(0.1,10.0);    
  }
  if (mass==2000 && coupling==5)
  {
    bwMean.setVal(2000); bwMean.setRange(1900,2100);
    bwSigma.setVal(11); bwSigma.setRange(2,25);
    // CB
    mean.setVal(1.2); mean.setRange(-25,25);
    sigma.setVal(15); sigma.setRange(0.1,20);
    alpha.setVal(1.5); alpha.setRange(-5.0,5.0);
    n_var.setVal(2.4); n_var.setRange(0.1,10.0);    
  }
  if (mass==2250 && coupling==10)
  {
    bwMean.setVal(2250); bwMean.setRange(2150,2350);
    bwSigma.setVal(11); bwSigma.setRange(2,35);
    // CB
    mean.setVal(1.2); mean.setRange(-50,50);
    sigma.setVal(15); sigma.setRange(0.1,25);
    alpha.setVal(1.5); alpha.setRange(-5.0,5.0);
    n_var.setVal(2.4); n_var.setRange(0.1,10.0);    
  }

  RooBreitWigner bwshape("bwshape","bwshape",minv,bwMean,bwSigma);
  RooFFTConvPdf myFit("myFit","myFit",minv,bwshape,crystalball);


  myFit.fitTo(data,FitOptions("mh"),Optimize(0));
  myFit.plotOn(mframe);
  
  myFit.paramOn(mframe,Layout(0.12,0.36,0.93)) ; 
  //   data.statOn(mframe);
  mframe->getAttText()->SetTextSize(0.03) ; 
  
  if (coupling==10) {
    sprintf(name,"signal mass %i GeV coupling 0.1",mass);
  } else if (coupling==5) {
    sprintf(name,"signal mass %i GeV coupling 0.05",mass);
  } else if (coupling==1) {
    sprintf(name,"signal mass %i GeV coupling 0.01",mass);
  }

  
  mframe->SetTitle(name);
  mframe->Draw();  
  
  mframe->SetMaximum(1.2*mframe->GetMaximum());
  mframe->SetMinimum(1e-1);
  c1->SetLogy(1);  
  
  c1->SetLogy(1);  
  sprintf(name,"signal_fit_%i_%i_log.png",mass,coupling);

  //c1->Print(name);

  //c1->SetLogy(0);  
  //sprintf(name,"signal_fit_%i_%i.png",mass,coupling);
  //c1->Print(name);
  //sprintf(name,"signal_fit_%i_%i.pdf",mass,coupling);
  //c1->Print(name);
  
  RooArgSet *paramList = myFit.getParameters(data) ;
  paramList->Print("v") ;
  // chi2
  //cout << "Chi2/ndf: " << mframe->chiSquare() << " / " << paramList->getSize() << " = " << mframe->chiSquare()/paramList->getSize() <<endl;
  cout << "Chi2reduced: " << mframe->chiSquare(paramList->getSize()) << endl;
  RooHistPdf saturatedModel("saturatedModel","saturatedModel",minv,data);
  RooNLLVar nllVarSatModel("nllVarSatModel","NLL Saturated Model",saturatedModel,data);
  RooNLLVar nllVarFitModel("nllVarFitModel","NLL Fit Model",myFit,data);
  double satVal = 2*(nllVarFitModel.getVal()-nllVarSatModel.getVal());
  int numBins = data.numEntries();
  //cout << "nllVarFitModel = " << nllVarFitModel.getVal() << " nllVarSatModel: " <<
  //  nllVarSatModel.getVal() << endl;
  cout << "SatVal: " << satVal << " numBins: " << numBins
    << " satVal/(numBins-numFitParams-1) = " << satVal/(numBins-paramList->getSize()-1) << endl;
  
  //// compute sigmaEff
  //float meanVal = histoOrig->GetMean();
  //int meanBin = histoOrig->FindBin(meanVal);
  //int binsToUse = 0;
  //float integral = histoOrig->Integral(meanBin-binsToUse,meanBin+binsToUse)/histoOrig->Integral();
  ////cout << "initial integral in meanBin only: " << integral << endl;
  //while(0.682-integral > 0.01)
  //{
  //  binsToUse++;
  //  integral = histoOrig->Integral(meanBin-binsToUse,meanBin+binsToUse)/histoOrig->Integral();
  //  //cout << "updated integral using " << binsToUse << " bins on either side: " << integral << endl;
  //}
  //float sigmaFull = histoOrig->GetBinCenter(meanBin+binsToUse) - histoOrig->GetBinCenter(meanBin-binsToUse);
  ////cout << "integral = " << integral << " lowerBinCenter: " << histoOrig->GetBinCenter(meanBin-binsToUse) <<
  ////  " upperBinCenter: " << histoOrig->GetBinCenter(meanBin+binsToUse) << " sigmaFull: " << sigmaFull << endl;
  //cout << "sigmaEff = " << sigmaFull/2.0 << endl;

  return;
  
}
