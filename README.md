# CppAss3
***
Run make in the home directory to compile the huffman code program.
Huffmancode program is run using the syntax:
`./huffmanCode <input_filename> <output_filename>`
for example:
`./huffmanCode text/test1.txt test1Compressed` will compress "test1.txt" files which is in the "/text" folder.
where <input> represents the file to be compressed and <output>.huffstrm will be the output compressed file bit stream file, <output>.hufftext will be the text version of the bitstream, and <output>.hdr will be the header file containing information about the code table.

To decode a huffman encoded file, use the following syntax
`./huffmanCode <compressed_bit_stream> <header> <decompressed_textfile_name>`
for examples:
`./huffmanCode test1Compressed.huffstrm test1Compressed.hdr test1Decompressed` will extract the test1.txt file.

## Unit Testing
Run make inside the "/testing" directory to compile the unit testing program.
To run the unit testing program type:
`./unitTesting`

## Files and Folders
* **main** - Driver class for the program. Checks for valid arguments and carries out necessary functions specified in the arguments.
* **HuffmanEncode** - class that contains the frequency table, huffman tree and the code table. this class carries out the actual encoding
* **HuffmanDecode** - class that decodes huffman encoded files
* **HuffmanTree** - class for the huffman tree
* **HuffmanNode** - Node class for the huffman tree
* **BitIn** - Classes to read bit streams
* **BitOut** - Classes to write bit streams
***
* **UnitTests** - is the unit tests for the huffmanCode
* **/text** - the text files used are contained here
* **/test** - Folder the has what the tree should look like as an image of the huffman trees of the text files used in unit testing
