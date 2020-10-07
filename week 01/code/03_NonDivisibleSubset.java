import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

public class NonDivisibleSubset {
    /**
     * Solution
     */
    private static int nonDivisibleSubset(int k, List<Integer> s) {
        int[] rem = new int[k];
        s.forEach(num -> rem[num % k]++);

        int result = (rem[0] > 0) ? 1 : 0;
        for (int i = 1; i < k / 2 + k % 2; i++) {
            result += Math.max(rem[i], rem[k - i]);
        }

        if (k % 2 == 0) {
            result += (rem[k / 2] > 0) ? 1 : 0;
        }

        return result;
    }

    @Test
    public void test() {
        Assert.assertEquals(3, nonDivisibleSubset(3, Arrays.asList(1, 7, 2, 4)));
        Assert.assertEquals(3, nonDivisibleSubset(4, Arrays.asList(19, 10, 12, 10, 24, 25, 22)));
        Assert.assertEquals(11, nonDivisibleSubset(7, Arrays.asList(278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771, 575, 436)));
    }
}
