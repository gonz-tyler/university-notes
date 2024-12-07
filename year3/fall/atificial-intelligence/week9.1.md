# Week 9.1: Learning 3 - Neural Networks (AIMA Ch 21)
## Notes
---
### **Key Concepts**

1. **Introduction to Neural Networks**:
    - **Neural Networks (NNs)** are a class of machine learning models inspired by the structure and function of the human brain.
    - A **neural network** is composed of layers of interconnected nodes (also called **neurons** or **units**).
    - These models are particularly effective for **non-linear problems** and are widely used in fields such as computer vision, natural language processing, and speech recognition.
2. **Structure of Neural Networks**:
    - **Input Layer**: This layer receives the input features. Each node corresponds to one feature in the input data.
    - **Hidden Layers**: These intermediate layers transform the input into more abstract representations. A network can have one or more hidden layers.
    - **Output Layer**: This layer produces the final output, which could be a classification label, a continuous value, or any other desired result.
    - **Weights and Biases**: Each connection between neurons has a weight, which indicates the strength of the connection. Each neuron also has a bias that shifts the activation function's output.
    
    The **feedforward architecture** is the most common type of neural network, where the data moves in one direction—from input to output.
    
3. **Activation Functions**:
    - Activation functions are applied to the output of each neuron to introduce **non-linearity**, allowing the network to learn complex patterns.
    
    Common activation functions include:
    
    - **Sigmoid**: A smooth function that outputs values between 0 and 1. Often used for binary classification.
    $$\sigma(x) = \frac{1}{1 + e^{-x}}$$
    - **Tanh (Hyperbolic Tangent)**: Outputs values between -1 and 1, often preferred over the sigmoid for its zero-centered output.
    $$\tanh(x) = \frac{e^x - e^{-x}}{e^x + e^{-x}}$$
    - **ReLU (Rectified Linear Unit)**: The most widely used activation function. It outputs the input directly if it is positive; otherwise, it outputs zero.
    $$\text{ReLU}(x) = \max(0, x)$$
    - **Softmax**: Used in the output layer for multi-class classification problems. It converts the raw output values into a probability distribution.
    $$\text{Softmax}(x_i) = \frac{e^{x_i}}{\sum_j e^{x_j}}$$
4. **Training Neural Networks**:
    - **Forward Propagation**: The input is passed through the network layer by layer to produce an output. Each neuron applies an activation function to its weighted sum of inputs.
    - **Loss Function**: The loss function quantifies how far the predicted output is from the actual output (target). The goal is to minimize this loss function during training.
        - For **regression problems**, a common loss function is **Mean Squared Error (MSE)**:
        $$\text{MSE} = \frac{1}{N} \sum_{i=1}^{N} (y_i - \hat{y}_i)^2$$
        - For **classification problems**, **Cross-Entropy Loss** (or log loss) is commonly used:
        $$L = - \sum_{i=1}^{N} y_i \log(\hat{y}_i)$$
        where $y_i$ is the true label and $\hat{y}_i$ is the predicted probability.
            
            
    - **Backpropagation**: The process of adjusting the weights and biases of the neural network to minimize the loss function.
        - Backpropagation uses the **chain rule of calculus** to calculate the gradient of the loss function with respect to each weight in the network.
        - **Gradient Descent**: This optimization algorithm adjusts the weights in the direction that reduces the loss, typically by using the negative gradient of the loss function. The update rule for weights is:
        $$w = w - \eta \frac{\partial L}{\partial w}$$
        where $\eta$ is the learning rate and $\frac{\partial L}{\partial w}$ is the gradient of the loss function with respect to weight $w$.
    - **Stochastic Gradient Descent (SGD)**: Instead of computing gradients using the entire dataset, **SGD** computes gradients using a single randomly selected training example (or a mini-batch), which speeds up the training process.
5. **Overfitting and Regularization**:
    - Neural networks, particularly deep networks, are prone to **overfitting**, where the model becomes too complex and fits the noise in the training data rather than the underlying patterns.
    
    Techniques for regularization include:
    
    - **L2 Regularization (Weight Decay)**: Adds a penalty to the loss function that discourages large weights.
    $$L_{\text{reg}} = L + \lambda \sum_{i} w_i^2$$
    where $\lambda$ is a regularization parameter.
    - **Dropout**: A technique that randomly disables (sets to zero) a fraction of the neurons during training to prevent over-reliance on any particular neuron and encourage generalization.
    - **Early Stopping**: Stops the training when the performance on the validation set stops improving, preventing the model from overfitting to the training data.
6. **Types of Neural Networks**:
    - **Feedforward Neural Networks (FNNs)**: The simplest type, where connections only move forward from input to output.
    - **Convolutional Neural Networks (CNNs)**: Specialized for image processing. They use **convolutional layers** to automatically learn spatial hierarchies in data.
    - **Recurrent Neural Networks (RNNs)**: Used for sequential data (e.g., time series, language). They have loops within the network to allow information to persist over time.
7. **Training Challenges**:
    - **Vanishing/Exploding Gradients**: In deep networks, gradients can either become too small (vanishing) or too large (exploding), making it difficult for the model to learn effectively.
    - **Learning Rate Tuning**: The choice of learning rate is crucial. Too high a learning rate may lead to overshooting the optimal solution, while too low a learning rate can result in slow convergence.
    - **Batch Normalization**: A technique used to stabilize and speed up training by normalizing the inputs to each layer, reducing issues with gradient scaling.
8. **Applications of Neural Networks**:
    - **Computer Vision**: Image classification, object detection, and segmentation, with CNNs being the state-of-the-art method.
    - **Natural Language Processing**: Tasks such as machine translation, speech recognition, and text classification using RNNs or transformers.
    - **Game Playing and Reinforcement Learning**: Neural networks are used to approximate value functions or policies in reinforcement learning algorithms, enabling systems like AlphaGo or autonomous agents.

---

### **Key Insights**:

- **Neural Networks** are powerful models that can learn complex patterns through multiple layers of transformations, making them suitable for a wide variety of tasks, particularly when the data is large and non-linear.
- The **training process** involves forward propagation to make predictions and backpropagation to update weights and minimize loss, typically using optimization techniques like **stochastic gradient descent**.
- To avoid **overfitting**, neural networks use **regularization techniques** like dropout and L2 regularization.
- **Deep learning** architectures like CNNs and RNNs have been transformative in fields such as **computer vision** and **natural language processing**.
- Despite their power, neural networks come with challenges, including managing **vanishing/exploding gradients** and selecting appropriate hyperparameters like the learning rate.

---

This chapter introduces **Neural Networks**, a key technology behind modern machine learning. Neural networks are highly versatile and have become the foundation for many state-of-the-art systems in AI, particularly in areas such as image and speech recognition. Understanding their architecture, training processes, and challenges is crucial to applying deep learning techniques effectively.
