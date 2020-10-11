#include<TCanvas.h>
#include<TF2.h>

void test()
{
    // Declare the canvas: we want it to be square so that the 2D plot
// is not distorted by scaling to the canvas size. We declare three canvasses
// to illustrate three drawing options.
TCanvas* c1 = new TCanvas("c1", "canvas 1 - 2D Function", 700, 700);
TCanvas* c2 = new TCanvas("c2", "canvas 2 - 2D Function", 700, 700);
TCanvas* c3 = new TCanvas("c3", "canvas 3 - 2D Function", 700, 700);
// Declare the function of both x and y. Constant values of the function will
// therefore be circles. This value increases quadratically with radial distance
// from the origin, so the z-value creates a parabolic surface.
TF2* myf2D = new TF2("myf2D", "pow(x,2) + pow(y,2)", -1.0, 1.0, -1.0, 1.0);
myf2D->SetTitle("z = f(x, y) = x^2 + y^2; x; y");
myf2D->SetLineColor(kBlue);
myf2D->SetLineStyle(1);
// Draw the function on canvas c1
c1->cd();
myf2D->Draw("cont3"); 
// Draw the function on canvas c2
c2->cd();
myf2D->Draw("cont4");
// Draw the function on canvas c3
c3->cd();
myf2D->Draw("surf3");
}
