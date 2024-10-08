import subprocess
import os
import re

def make_and_run():
    
    command_pack = ["make", "pack"]
    subprocess.run(command_pack)
    
    command_test = ["g++", "-std=c++17", "./test/main.cc", "-o", "./test/test", "-Lbuild", "-leasytf"]
    command_correct = ["g++", "-std=c++17", "./test/main.cc", "-o", "./test/correct", "-Ltest", "-leasytf_correct"]
    
    subprocess.run(command_test)
    subprocess.run(command_correct)
    
    
    command_touch_test = ["./test/test"]
    command_touch_correct = ["./test/correct"]
    
    with open("./test/test.txt", "w") as file:
        subprocess.run(command_touch_test, stdout=file,
                       stderr=subprocess.STDOUT, text=True, check=True)
    
    with open("./test/correct.txt", "w") as file:
        subprocess.run(command_touch_correct, stdout=file,
                       stderr=subprocess.STDOUT, text=True, check=True)

def read():
    fp_test = open("./test/test.txt", "r");
    fp_correct = open("./test/correct.txt", "r");
    
    lines_test = fp_test.readlines()
    lines_corrct = fp_correct.readlines()
    
    if(lines_test != lines_corrct):
        print("This test is Failed!\n")
        return
    
    for line_test, line_corrct in zip(lines_test, lines_corrct):
        if(line_test != line_corrct):
            print("This test is Failed!\n")
            return

    print("This test is Pass!\n")
    
def main():
    os.environ["CPLUS_INCLUDE_PATH"] = "$CPLUS_INCLUDE_PATH:./include"
    
    make_and_run()
    read()
    
main()