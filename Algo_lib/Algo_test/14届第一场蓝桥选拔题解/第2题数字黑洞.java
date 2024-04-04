import java.util.Scanner;
import java.util.Arrays;

 class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int k = 0;

		String str = sc.next(); //接受字符串容易分解

		while (!str.equals(6174 + "")) { //判断循环条件

			char[] strs = new char[4]; //定义char类型数组接受字符串

			for (int i = 0; i < strs.length; i++) {

				strs[i] = str.charAt(i); //将分解的字符串装到数组里面

			}

			Arrays.sort(strs); //倒序

			String max = ""; //最大值-字符串类型

			String min = ""; //最小值-字符串类型

			max = "" + strs[3] + strs[2] + strs[1] + strs[0]; //字符串拼接

			min = "" + strs[0] + strs[1] + strs[2] + strs[3]; //字符串拼接

			str = (Integer.parseInt(max) - Integer.parseInt(min)) + "";

			k++;

		}

		System.out.println(k);
	}
}