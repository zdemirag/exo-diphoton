void read(){

  //TFile *file = new TFile("/afs/cern.ch/work/z/zdemirag/work/Diphoton/CMSSW_5_3_2_patch4/src/May28/histograms_ExoDiPhotonAnalyzer_PFDec14th_DataABCD.root","READ");

  TFile *file = new TFile("/afs/cern.ch/work/z/zdemirag/work/Diphoton/CMSSW_5_3_2_patch4/src/May28/data_fineBin.root","READ");
  TH1F *h = (TH1F*)file->Get("h_Diphoton_Minv_FineBinning");

 TFile *filenew = new TFile("/afs/cern.ch/work/z/zdemirag/work/Diphoton/CMSSW_5_3_2_patch4/src/May28/histograms_ExoDiPhotonAnalyzer_PFDec14th_DataABCD_ZEYNEP.root","RECREATE");

 TTree *tree = new TTree("T","An example of a ROOT tree");

 float mass;
 tree->Branch("mass", &mass,"mass/F");

  for(int i = 0; i<h->GetNbinsX(); i++){
    for(int j = 0; j<h->GetBinContent(i); j++ ){
        std::cout << "GetBinCenter: " << h->GetBinLowEdge(i)<< " Get Bin Center2: " << h->GetBinCenter(i) <<" BinContent: " << h->GetBinContent(i) << std::endl;    



        //mass = h->GetBinLowEdge(i); 
        mass = h->GetBinCenter(i);
        tree->Fill();
    }
  }

  h->Draw();
  tree->Write();

}
