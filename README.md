## SENG 440 Project
### Huffman encoding

Compile the code with the command

```bash
make opt
```

This will make an executable called `decode`.

Pass the program input as command line arguments. Test input can be found [testinput.txt](./testinput.txt) and can be passed into the program with the following command:

```bash
./decode < testinput.txt
```

To make a gprof profile, use the command

```bash
make profile
```

This will create a file called `a.out`. Execute this file and pass it the test data to complete the profile.

```bash
./a.out < testinmput.txt
```

Finally, read the profile with the `gprof` command.