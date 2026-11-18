/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

import java.util.*;
import java.io.*;
import java.io.*;

//1. 정상을 찾는다
// 중앙이 왼쪽과 오른쪽보다 크다면, 왼/오른쪽으로 나눠서 찾는다
// 왼 < 중 < 오 라면, peak가 오른쪽 or 포함
// 왼 > 중 > 오 라면, peak가 왼쪽 or 포함

class Solution {
    int peakIdx;        //init -1
    HashMap<Integer, Integer> map;
    final int MUL = 100000;     //10^5

    public int getVal(int idx, MountainArray mountainArr) {
        Integer v = map.get(idx);
        if(v == null) {
            int val = mountainArr.get(idx);
            map.put(idx, val);
            return val;
        }
        return v;
    }

    public void findPeak(int l, int r, int len, MountainArray mountainArr) {
        if(peakIdx!=-1) return;     //이미 찾은 경우
        int m = l+(r-l)/2;
        if(m==len-1) return;
        int mv = getVal(m, mountainArr);
        int rv = getVal(m+1, mountainArr);
        if(mv > rv) {
            if(m>0 && getVal(m-1, mountainArr) < mv) {
                peakIdx = m;
                return;
            }
            findPeak(l, m, len, mountainArr);
        } else {
            findPeak(m, r, len, mountainArr);
        }
    }

    public int findInMountainArray(int target, MountainArray mountainArr) {
        int len = mountainArr.length();
        map = new HashMap<>();

        //1. peak 찾기
        peakIdx = -1;
        findPeak(0, len-1, len, mountainArr);
        //2. peak 기준 왼쪽으로 찾기
        int l = 0;
        int r = peakIdx;
        while(l<=r) {
            int m = l + (r-l)/2;
            int val = getVal(m, mountainArr);
            if(val == target) {
                return m;
            } else if(val < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        //3. peak 기준 오른쪽으로 찾기
        l = peakIdx;
        r = len-1;
        while(l<=r) {
            int m = l + (r-l)/2;
            int val = getVal(m, mountainArr);
            if(val == target) {
                return m;
            } else if(val < target) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return -1;
    }
}