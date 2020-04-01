import PyPDF2
import argparse


parser = argparse.ArgumentParser()
parser.add_argument('file_name', type=str)
args = parser.parse_args()

str = ''
pdf_file = open(args.file_name+'.pdf', 'rb')
read_pdf = PyPDF2.PdfFileReader(pdf_file)
number_of_pages = read_pdf.getNumPages()

for x in range(number_of_pages):
    page = read_pdf.getPage(x)
    page_content = page.extractText()

    for i in page_content:
        if i is not ' ':
            str = str + i
        else:

            str = str + f' {x} \n'

#print(str)
file1 = open("MyFile.txt", "w")

file1.write(str)

file1.close()
