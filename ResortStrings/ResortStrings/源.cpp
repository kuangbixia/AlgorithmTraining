#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

/*vector<string> sortStrings(vector<string> str, int n) {
    // write code here
    sort(str.begin(), str.end(), [](string s1, string s2) {
        if (s1.length() != s2.length()) {
            return s1.length() < s2.length();
        }
        else {
            return s1 < s2;
        }
        });
    for (int i = 1; i < str.size(); i++) {
        int length = str[i].length();
        int k = i - 1;
        while (k >= 0 && str[k].length() == length) {
            vector<char>temp1(length, ' ');
            vector<char>temp2(length, ' ');
            for (int j = 0; j < length; j++) {
                temp1[j] = str[i][j];
                temp2[j] = str[k][j];
            }
            sort(temp1.begin(), temp1.end());
            sort(temp2.begin(), temp2.end());
            int j;
            for (j = 0; j < length; j++) {
                if (temp1[j] != temp2[j]) {
                    break;
                }
            }
            if (j == length) {
                str.erase(str.begin() + i);
                i--;
            }
            k--;
        }
    }
    
    sort(str.begin(), str.end());
    return str;
}*/

vector<string> sortStrings(vector<string> str, int n) {
    set<string>aset;
    sort(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++) {
        string temp = str[i];
        sort(temp.begin(), temp.end());
        if (aset.count(temp) > 0) {
            str.erase(find(str.begin(), str.end(), str[i]));
            i--;
        }
        else {
            aset.insert(temp);
        }
    }
    return str;
}

int main() {
    vector<string>in{ "emmaldzsvjggzfoda","skmjhsm","zjwmkgufsvwrwyvrhk","vyksgrwwjmwrhzfvuk","wfszrykvjrmuwhkvgw","kwrwuwjvksyvhmrzfg","kom","mko","mko","nezrxmdjgjqexmqz","gjmqdrzqzjeemxxn","qqxedgjjmrznmxez","xxgmjezerjnqmzdq","vwcmmngdsvzx","xvmdvwscgnmz","msnvvczxdgwm","izmvzrhltsiubcukc","cslnzuenr","rznulsenc","lnsnucrez","gkyfvvni","gikvvynf","ivkfyvng","vygfvikn","nwxkeyhnvniquhpapw","wnhyknvanhepwquxip","rrpujexoukmmrnmpdzcf","ksirghrnjx","ixrhgkrnjs","kup","kpu","kpu","emnetqjwnfwi","qpozvklf","qpvkolfz","flpkvoqz","zlkpvfoq","zldjqciktnevrkb","vklqjdrktcebizn","ntrqkvebiljczkd","nkktcebjirqvldz","mytegbucud","gbtcyuemud","gctmuedybu","ahgeomesgcehvk","oamshhecevggek","gmcekevoehsahg","gvgeacmheeoksh","ma","am","am","wxdyddyrenzsylfwx","syedwdylxrwfyxzdn","dwsddyelxywrxyfnz","rdrrfuowxukryfmli","qdjzmdobajs","ymysuotfxpboc","awzccscrkozbhygrkvv","ovrgybhswrczzkcacvk","zcrwkyhrzkgacvsocbv","vzwgzosrkvkcrcybahc","ftytv","ttvyf","tfyvt","vtytf","pggunxuyduy","qijygauutkt","aytqutkugji","itjutqugaky","nfoenumvnmannkkhmueo","ounmkhknefvemnmannou","eonmenfkhmuaonnnumvk","mvnouemekonfamnnnhku","a" };
    vector<string>out = sortStrings(in, 74);
    cout << "after sort:" << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }
    /*map<int, string>amap;
    amap.insert(make_pair(3, "ccc"));
    amap[1] = "aaa";
    auto it = amap.find(1);
    cout << it->first << " " << it->second << endl;
    it = amap.erase(it);*/
	return 0;
}