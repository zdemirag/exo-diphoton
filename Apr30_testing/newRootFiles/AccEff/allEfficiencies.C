{
//=========Macro generated from canvas: c1_n5/c1_n5
//=========  (Thu Dec 19 14:52:54 2013) by ROOT version5.32/00
   TCanvas *c1_n5 = new TCanvas("c1_n5", "c1_n5",0,0,700,500);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1_n5->SetHighLightColor(2);
   c1_n5->Range(229.7297,0.3720779,3945.946,0.8915584);
   c1_n5->SetFillColor(0);
   c1_n5->SetBorderMode(0);
   c1_n5->SetBorderSize(2);
   c1_n5->SetTickx(1);
   c1_n5->SetTicky(1);
   c1_n5->SetLeftMargin(0.14);
   c1_n5->SetRightMargin(0.12);
   c1_n5->SetTopMargin(0.08);
   c1_n5->SetBottomMargin(0.15);
   c1_n5->SetFrameFillStyle(0);
   c1_n5->SetFrameLineWidth(2);
   c1_n5->SetFrameBorderMode(0);
   c1_n5->SetFrameFillStyle(0);
   c1_n5->SetFrameLineWidth(2);
   c1_n5->SetFrameBorderMode(0);
   
   TH1F *test = new TH1F("test","",10,750,3500);
   test->SetMinimum(0.45);
   test->SetMaximum(0.85);
   test->SetStats(0);
   test->SetLineWidth(2);
   test->SetMarkerStyle(8);
   test->SetMarkerSize(0.8);
   test->GetXaxis()->SetTitle("M_{1} [GeV]");
   test->GetXaxis()->SetNdivisions(506);
   test->GetXaxis()->SetLabelFont(42);
   test->GetXaxis()->SetTitleOffset(1.2);
   test->GetXaxis()->SetTitleFont(42);
   test->GetYaxis()->SetTitle("efficiency");
   test->GetYaxis()->SetNdivisions(506);
   test->GetYaxis()->SetLabelFont(42);
   test->GetYaxis()->SetTitleOffset(1.2);
   test->GetYaxis()->SetTitleFont(42);
   test->GetZaxis()->SetLabelFont(42);
   test->GetZaxis()->SetTitleSize(0.06);
   test->GetZaxis()->SetTitleOffset(1.1);
   test->GetZaxis()->SetTitleFont(42);
   test->Draw("");
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   TGraph *graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(3);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.8134434223);
   graph->SetPoint(1,1000,0.8053950071);
   graph->SetPoint(2,1250,0.8026521802);
   graph->SetPoint(3,1500,0.7973504663);
   graph->SetPoint(4,1750,0.7964116931);
   graph->SetPoint(5,2000,0.7940440178);
   graph->SetPoint(6,2250,0.7865680456);
   graph->SetPoint(7,2500,0.7833413482);
   graph->SetPoint(8,3000,0.7570303082);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,525,3225);
   Graph_Graph1->SetMinimum(0.751389);
   Graph_Graph1->SetMaximum(0.8190847);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineWidth(2);
   Graph_Graph1->SetMarkerStyle(8);
   Graph_Graph1->SetMarkerSize(0.8);
   Graph_Graph1->GetXaxis()->SetNdivisions(506);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetNdivisions(506);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph1->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineStyle(3);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1250,0.8045201302);
   graph->SetPoint(1,1500,0.804307878);
   graph->SetPoint(2,1750,0.7997083664);
   graph->SetPoint(3,2000,0.7894309163);
   graph->SetPoint(4,2250,0.7917349339);
   graph->SetPoint(5,2500,0.7809233069);
   graph->SetPoint(6,2750,0.7657097578);
   graph->SetPoint(7,3000,0.7590904832);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,1075,3175);
   Graph_Graph2->SetMinimum(0.7545475);
   Graph_Graph2->SetMaximum(0.8090631);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);
   Graph_Graph2->SetLineWidth(2);
   Graph_Graph2->SetMarkerStyle(8);
   Graph_Graph2->SetMarkerSize(0.8);
   Graph_Graph2->GetXaxis()->SetNdivisions(506);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetNdivisions(506);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph2->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(8);
   graph->SetLineStyle(3);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(8);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1500,0.8003898263);
   graph->SetPoint(1,1750,0.7966074347);
   graph->SetPoint(2,2000,0.7966414094);
   graph->SetPoint(3,2250,0.7878504395);
   graph->SetPoint(4,2500,0.7874897718);
   graph->SetPoint(5,2750,0.7717314363);
   graph->SetPoint(6,3000,0.75215137);
   graph->SetPoint(7,3250,0.7384622097);
   graph->SetPoint(8,3500,0.7274891138);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,1300,3700);
   Graph_Graph3->SetMinimum(0.720199);
   Graph_Graph3->SetMaximum(0.8076799);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetLineWidth(2);
   Graph_Graph3->SetMarkerStyle(8);
   Graph_Graph3->SetMarkerSize(0.8);
   Graph_Graph3->GetXaxis()->SetNdivisions(506);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetNdivisions(506);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineStyle(2);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.7252358198);
   graph->SetPoint(1,1000,0.7200660706);
   graph->SetPoint(2,1250,0.7245261669);
   graph->SetPoint(3,1500,0.7191947103);
   graph->SetPoint(4,1750,0.7154061198);
   graph->SetPoint(5,2000,0.7176789045);
   graph->SetPoint(6,2250,0.7121093273);
   graph->SetPoint(7,2500,0.7090033889);
   graph->SetPoint(8,3000,0.6838417053);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,525,3225);
   Graph_Graph4->SetMinimum(0.6797023);
   Graph_Graph4->SetMaximum(0.7293752);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);
   Graph_Graph4->SetLineWidth(2);
   Graph_Graph4->SetMarkerStyle(8);
   Graph_Graph4->SetMarkerSize(0.8);
   Graph_Graph4->GetXaxis()->SetNdivisions(506);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetNdivisions(506);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph4->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineStyle(2);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1250,0.7256346941);
   graph->SetPoint(1,1500,0.7271683216);
   graph->SetPoint(2,1750,0.7234582305);
   graph->SetPoint(3,2000,0.7136178613);
   graph->SetPoint(4,2250,0.7182238102);
   graph->SetPoint(5,2500,0.7092662454);
   graph->SetPoint(6,2750,0.6964653134);
   graph->SetPoint(7,3000,0.6942833662);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","Graph",100,1075,3175);
   Graph_Graph5->SetMinimum(0.6909949);
   Graph_Graph5->SetMaximum(0.7304568);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);
   Graph_Graph5->SetLineWidth(2);
   Graph_Graph5->SetMarkerStyle(8);
   Graph_Graph5->SetMarkerSize(0.8);
   Graph_Graph5->GetXaxis()->SetNdivisions(506);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetNdivisions(506);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph5->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph5->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(8);
   graph->SetLineStyle(2);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(8);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1500,0.7212222219);
   graph->SetPoint(1,1750,0.7225775123);
   graph->SetPoint(2,2000,0.7199979424);
   graph->SetPoint(3,2250,0.7138985991);
   graph->SetPoint(4,2500,0.7154785395);
   graph->SetPoint(5,2750,0.6998351216);
   graph->SetPoint(6,3000,0.6819654107);
   graph->SetPoint(7,3250,0.6721684337);
   graph->SetPoint(8,3500,0.6640768647);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,1300,3700);
   Graph_Graph6->SetMinimum(0.6582268);
   Graph_Graph6->SetMaximum(0.7284276);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);
   Graph_Graph6->SetLineWidth(2);
   Graph_Graph6->SetMarkerStyle(8);
   Graph_Graph6->SetMarkerSize(0.8);
   Graph_Graph6->GetXaxis()->SetNdivisions(506);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetNdivisions(506);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph6->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph6->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,750,0.5817610025);
   graph->SetPoint(1,1000,0.5789980888);
   graph->SetPoint(2,1250,0.5886032581);
   graph->SetPoint(3,1500,0.5913456082);
   graph->SetPoint(4,1750,0.5857864022);
   graph->SetPoint(5,2000,0.5891607404);
   graph->SetPoint(6,2250,0.589399457);
   graph->SetPoint(7,2500,0.5808377266);
   graph->SetPoint(8,3000,0.5627461672);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","Graph",100,525,3225);
   Graph_Graph7->SetMinimum(0.5598862);
   Graph_Graph7->SetMaximum(0.5942056);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);
   Graph_Graph7->SetLineWidth(2);
   Graph_Graph7->SetMarkerStyle(8);
   Graph_Graph7->SetMarkerSize(0.8);
   Graph_Graph7->GetXaxis()->SetNdivisions(506);
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetNdivisions(506);
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph7->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph7->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(4);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1250,0.587616086);
   graph->SetPoint(1,1500,0.5908098817);
   graph->SetPoint(2,1750,0.5912085772);
   graph->SetPoint(3,2000,0.5827744007);
   graph->SetPoint(4,2250,0.5902746916);
   graph->SetPoint(5,2500,0.5835202932);
   graph->SetPoint(6,2750,0.5751355886);
   graph->SetPoint(7,3000,0.5754855871);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","Graph",100,1075,3175);
   Graph_Graph8->SetMinimum(0.5735283);
   Graph_Graph8->SetMaximum(0.5928159);
   Graph_Graph8->SetDirectory(0);
   Graph_Graph8->SetStats(0);
   Graph_Graph8->SetLineWidth(2);
   Graph_Graph8->SetMarkerStyle(8);
   Graph_Graph8->SetMarkerSize(0.8);
   Graph_Graph8->GetXaxis()->SetNdivisions(506);
   Graph_Graph8->GetXaxis()->SetLabelFont(42);
   Graph_Graph8->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph8->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetNdivisions(506);
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph8->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph8->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph8);
   
   multigraph->Add(graph,"l");
   
   graph = new TGraph(9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineColor(8);
   graph->SetLineWidth(4);
   graph->SetMarkerColor(8);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(0.8);
   graph->SetPoint(0,1500,0.5902889371);
   graph->SetPoint(1,1750,0.5854107738);
   graph->SetPoint(2,2000,0.5896477699);
   graph->SetPoint(3,2250,0.587131083);
   graph->SetPoint(4,2500,0.5889280438);
   graph->SetPoint(5,2750,0.5754534602);
   graph->SetPoint(6,3000,0.5673174858);
   graph->SetPoint(7,3250,0.5563133955);
   graph->SetPoint(8,3500,0.5509947538);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","Graph",100,1300,3700);
   Graph_Graph9->SetMinimum(0.5470653);
   Graph_Graph9->SetMaximum(0.5942184);
   Graph_Graph9->SetDirectory(0);
   Graph_Graph9->SetStats(0);
   Graph_Graph9->SetLineWidth(2);
   Graph_Graph9->SetMarkerStyle(8);
   Graph_Graph9->SetMarkerSize(0.8);
   Graph_Graph9->GetXaxis()->SetNdivisions(506);
   Graph_Graph9->GetXaxis()->SetLabelFont(42);
   Graph_Graph9->GetXaxis()->SetLabelSize(0.073);
   Graph_Graph9->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetNdivisions(506);
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph9->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph9->GetZaxis()->SetTitleOffset(1.1);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph9);
   
   multigraph->Add(graph,"l");
   multigraph->Draw("L");
   
   TLegend *leg = new TLegend(0.42,0.2,0.73,0.4,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph","Loose PFID #tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(3);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Loose PFID #tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(3);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Loose PFID #tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(3);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Med PFID #tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(2);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Med PFID #tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(2);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Med PFID #tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(2);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Tight PFID #tilde{k} = 0.01","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Tight PFID #tilde{k} = 0.05","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry=leg->AddEntry("Graph","Tight PFID #tilde{k} = 0.1","l");
   entry->SetLineColor(8);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   leg->Draw();
   
   TH1F *test__1 = new TH1F("test__1","",10,750,3500);
   test__1->SetMinimum(0.45);
   test__1->SetMaximum(0.85);
   test__1->SetDirectory(0);
   test__1->SetStats(0);
   test__1->SetLineWidth(2);
   test__1->SetMarkerStyle(8);
   test__1->SetMarkerSize(0.8);
   test__1->GetXaxis()->SetTitle("M_{1} [GeV]");
   test__1->GetXaxis()->SetNdivisions(506);
   test__1->GetXaxis()->SetLabelFont(42);
   test__1->GetXaxis()->SetTitleOffset(1.2);
   test__1->GetXaxis()->SetTitleFont(42);
   test__1->GetYaxis()->SetTitle("efficiency");
   test__1->GetYaxis()->SetNdivisions(506);
   test__1->GetYaxis()->SetLabelFont(42);
   test__1->GetYaxis()->SetTitleOffset(1.2);
   test__1->GetYaxis()->SetTitleFont(42);
   test__1->GetZaxis()->SetLabelFont(42);
   test__1->GetZaxis()->SetTitleSize(0.06);
   test__1->GetZaxis()->SetTitleOffset(1.1);
   test__1->GetZaxis()->SetTitleFont(42);
   test__1->Draw("sameaxis");
   c1_n5->Modified();
   c1_n5->cd();
   c1_n5->SetSelected(c1_n5);
}
