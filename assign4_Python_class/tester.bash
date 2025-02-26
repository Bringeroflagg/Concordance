#!/bin/bash

tester() {
    fail_check[0]=$(./official-tester4.py in01.txt | diff out01.txt -)
    fail_check[1]=$(./official-tester4.py in02.txt | diff out02.txt -)
    fail_check[2]=$(./official-tester4.py in03.txt -e english.txt | diff out03.txt -)
    fail_check[3]=$(./official-tester4.py in04.txt -e english.txt | diff out04.txt -)
    fail_check[4]=$(./official-tester4.py in05.txt -e english.txt | diff out05.txt -)
    fail_check[5]=$(./official-tester4.py in06.txt -e english.txt | diff out06.txt -)
    fail_check[6]=$(./official-tester4.py in07.txt -e english.txt | diff out07.txt -)
    fail_check[7]=$(./official-tester4.py in08.txt -e latin.txt | diff out08.txt -)
    fail_check[8]=$(./official-tester4.py in09.txt -e latin.txt | diff out09.txt -)
    fail_check[9]=$(./official-tester4.py in10.txt -e deutsch.txt | diff out10.txt -)
    fail_check[10]=$(./official-tester4.py in11.txt -e english.txt | diff out11.txt -)
    fail_check[11]=$(./official-tester4.py in12.txt -e english-2.txt | diff out12.txt -)
    fail_check[12]=$(./official-tester4.py in13.txt -e english-2.txt | diff out13.txt -)
    fail_check[13]=$(./official-tester4.py in14.txt -e english-2.txt | diff out14.txt -)
    fail_check[14]=$(./official-tester4.py in15.txt -e latin.txt | diff out15.txt -)
    fail_check[15]=$(./official-tester4.py in16.txt -e latin.txt | diff out16.txt -)
    fail_check[16]=$(./official-tester4.py in17.txt -e latin-2.txt | diff out17.txt -)
    fail_check[17]=$(./official-tester4.py in18.txt -e latin-2.txt | diff out18.txt -)
    fail_check[18]=$(./official-tester4.py in19.txt -e deutsch-2.txt | diff out19.txt -)
    fail_check[19]=$(./official-tester4.py in20.txt -e deutsch-2.txt | diff out20.txt -)
    fail_check[20]=$(./official-tester4.py in21.txt | diff out21.txt -)
    fail_check[21]=$(./official-tester4.py in22.txt -e english-2.txt | diff out22.txt -)
    fail_check[22]=$(./official-tester4.py in23.txt -e english-2.txt | diff out23.txt -)
    fail_check[23]=$(./official-tester4.py in24.txt -e english-2.txt | diff out24.txt -)
    fail_check[24]=$(./official-tester4.py in25.txt -e english-2.txt | diff out25.txt -)

    n=1
    passed = 0
    for i in "${fail_check[@]}"
    do
        echo ====================
        if ["$i" == ""]
        then
            echo Test "$n" passed
            let "passed++"
        else
            echo Test "$n" failed
        fi
        echo ==================== 
        echo

        let "n++"
    done
    let "n--"
    

    echo [ Passed "$passed" out of "$n" ]
}

time tester