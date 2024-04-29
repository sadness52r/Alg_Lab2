#include "DataGenerator.hpp"
#include "Alg1Naive.hpp"
#include "Alg2Map.hpp"
#include "Alg3SegTree.hpp"
#include <chrono>
#include <fstream>
std::ofstream fout;

int main(){
    fout.open("..\\resources\\logs.txt");
    
    int numRects = 1;
    for (size_t i = 0; i < 9; i++)
    {
        DataGenerator dataGenerator(numRects, 100000);
        std::vector<Rectangle> rects = dataGenerator.CreateRectangles();
        std::vector<Point> points = dataGenerator.CreatePoints();

        Alg1Naive alg1;

        fout << "Num rectangles: " << numRects << std::endl;

        long long total_time = 0;
	    std::chrono::steady_clock::time_point start;
	    std::chrono::steady_clock::time_point end;
        for (size_t j = 0; j < NUM_STEPS; j++)
        {
            start = std::chrono::steady_clock::now();

            std::vector<int> ansAlg1 = alg1.CalcAnswers(rects, points);

            end = std::chrono::steady_clock::now();
		    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }
        fout << "Alg1:\n\tAlg time: " << total_time / NUM_STEPS << std::endl;
	    std::cout << "Result from algorythm 1 - Time: " << total_time / NUM_STEPS << std::endl;

        total_time = 0;
        long long total_prepoc_time = 0;
        for (size_t j = 0; j < NUM_STEPS; j++)
        {
            start = std::chrono::steady_clock::now();
            Alg2Map alg2(rects, points);
            end = std::chrono::steady_clock::now();
            total_prepoc_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            start = std::chrono::steady_clock::now();
            std::vector<int> ansAlg2 = alg2.CalcAnswers(rects, points);
            end = std::chrono::steady_clock::now();
		    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }
        fout << "Alg2:\n\tPreprocess time: " << total_prepoc_time / NUM_STEPS << "\n\tAlg time: " << total_time / NUM_STEPS << std::endl;
	    std::cout << "Result from algorythm 2 - Time: " << total_time / NUM_STEPS << std::endl;

        total_time = 0;
        total_prepoc_time = 0;
        for (size_t j = 0; j < NUM_STEPS; j++)
        {
            start = std::chrono::steady_clock::now();
            Alg3SegTree alg3(rects);
            end = std::chrono::steady_clock::now();
            total_prepoc_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            
            start = std::chrono::steady_clock::now();
            std::vector<int> ansAlg3 = alg3.CalcAnswers(rects, points);
            end = std::chrono::steady_clock::now();
		    total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }
        fout << "Alg3:\n\tPreprocess time: " << total_prepoc_time / NUM_STEPS << "\n\tAlg time: " << total_time / NUM_STEPS << std::endl;
	    std::cout << "Result from algorythm 3 - Time: " << total_time / NUM_STEPS << std::endl;

        numRects *= 2;
    }
    fout.close();

    // DataGenerator dataGenerator(4, 6);
    // std::vector<Rectangle> rects = dataGenerator.CreateRectangles();
    // std::vector<Point> points = dataGenerator.CreatePoints();

    // std::vector<Rectangle> rects1 = {Rectangle(Point(2, 2), Point(6, 8)), Rectangle(Point(5, 4), Point(9, 10)), Rectangle(Point(4, 0), Point(11, 6)), Rectangle(Point(8, 2), Point(12, 12))};
    // std::vector<Point> points1 = {Point(2, 2), Point(12, 12), Point(10, 4), Point(5, 5), Point(2, 10), Point(2, 8)};

    // Alg1Naive alg1;
    // std::vector<int> ansAlg1 = alg1.CalcAnswers(rects1, points1);
    
    // Alg2Map alg2(rects1, points1);
    // std::vector<int> ansAlg2 = alg2.CalcAnswers(rects1, points1);

    // Alg3SegTree alg3(rects1);
    // std::vector<int> ansAlg3 = alg3.CalcAnswers(rects1, points1);
    
    // for (size_t i = 0; i < ansAlg3.size(); i++)
    // {
    //     std::cout << ansAlg3[i] << "\n";
    // }
    
    return 0;
}