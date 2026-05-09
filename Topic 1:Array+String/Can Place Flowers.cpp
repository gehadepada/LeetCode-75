class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (n == 1) {
                if (flowerbed[0] == 0) {
                    return true;
                } else {
                    return false;
                }
            } else if (n >= 2) {
                return false;
            } else {
                return true;
            }
        }
        if (flowerbed.size() >= 2) {
            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                n--;
                flowerbed[0] = 1;
            }
            if (flowerbed[flowerbed.size() - 1] == 0 &&
                flowerbed[flowerbed.size() - 2] == 0) {
                n--;
                flowerbed[flowerbed.size() - 1] = 1;
            }
        }
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 &&
                flowerbed[i + 1] == 0) {
                i++;
                n--;
            }
        }
        if (n <= 0) {
            return true;
        }
        return false;
    }
};