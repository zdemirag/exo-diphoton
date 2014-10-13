import os
import sys

def renamer() :
    for filename in os.listdir('.') :
        if filename.endswith('pdf'):
            epsfile = filename.replace(".pdf",".eps")
            pngfile = filename.replace(".pdf",".png")
            os.system("pdftops -eps "+filename)
            os.system("convert "+epsfile+" "+pngfile)
            #print "converted " + filename + " to " + pngfile
            os.system("rm *.eps")

# test the function/module
if __name__ == '__main__':
    renamer()
