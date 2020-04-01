from PyPDF2 import PdfFileReader
import argparse
import progressbar
from time import sleep


parser = argparse.ArgumentParser()
parser.add_argument('file_name', type=str)
args = parser.parse_args()

str = ''
#print(args.file_name)
pdf_file = open(args.file_name+'.pdf', 'rb')
read_pdf = PdfFileReader(pdf_file)
number_of_pages = read_pdf.getNumPages()

bar = progressbar.ProgressBar(maxval=number_of_pages, widgets=[progressbar.Bar('|', '[', ']'), ' ', progressbar.Percentage()])

bar.start()

file1 = open(args.file_name+".txt", "w", encoding="utf-8")

for x in range(number_of_pages):
    page = read_pdf.getPage(x)
    page_content = page.extractText()

    bar.update(int(x))
    sleep(0.1)
    #print(f"{(x/number_of_pages)*100} % \n")
    str = ''
    for i in page_content:
        if i is not ' ':
            str = str + i
            #print(str)
        else:
            str = str + f" {x + 1} \n"
            file1.write(str)

bar.finish()
file1.close()
