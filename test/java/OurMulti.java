public class OurMulti {
  public static void main(String[] args) {
    
//NOTE: Esse caso NÃO passa

    int[][] array_int = new int[10][10];

    array_int[0][0] = 1;
    array_int[0][1] = 2;
    array_int[0][2] = 3;
    array_int[9][5] = 4;

    System.out.println(array_int[0][0]);
    System.out.println(array_int[1][0]);

//NOTE: Esse caso NÃO passa

    // Integer[] arrayInt = new Integer[3];

    // arrayInt[0] = 1;
    // arrayInt[1] = 2;
    // arrayInt[2] = 3;

    // System.out.println(arrayInt[0]);
    // System.out.println(arrayInt[1]);
    // System.out.println(arrayInt[2]);

//NOTE: Esse caso passa

  // String[] arrayOfString = new String[10];
  // arrayOfString[0] = "String 1";
  // arrayOfString[9] = "String 2";
  // System.out.println(arrayOfString[0]);
  // System.out.println(arrayOfString[9]);

//NOTE: Esse caso passa

    int[][] int_array = new int[3][3];
    int_array[0][2] = 1;
    int_array[1][2] = 2;
    int_array[2][2] = 10;
    System.out.println(int_array[0][2]);
    System.out.println(int_array[1][2]);
    System.out.println(int_array[2][2]);

    //NOTE: Esse caso passa

    // int[] arrayOfString = new int[3];
    // arrayOfString[0] = 1;
    // arrayOfString[1] = 2;
    // arrayOfString[2] = 10;
    // System.out.println(arrayOfString[0]);
    // System.out.println(arrayOfString[1]);
    // System.out.println(arrayOfString[2]);

  }
}