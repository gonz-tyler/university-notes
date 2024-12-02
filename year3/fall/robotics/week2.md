# Week 2: The Robot Operating System (ROS)

## Notes

---

### Key Insight
- ROS and ROS 2 utilize a modular architecture with nodes communicating through a publish-subscribe model, enhancing flexibility and scalability.
- Node discovery in ROS 2 is automated, allowing for dynamic communication as nodes are started and shut down.
- The use of QoS policies in ROS 2 is crucial for adapting communication strategies to meet the requirements of different operational environments.
- Parameters can be set for nodes at startup or runtime, allowing for customizable configurations based on specific user needs.
- Visualization tools like RViz and various simulators play a vital role in the development and testing of robotic systems.

### Frequently Asked Questions
What is the purpose of a ROS node?
- A ROS node is a modular component of a robotic system, designed to perform a specific function and communicate with other nodes.
How does the publish-subscribe model work in ROS?
- In the publish-subscribe model, nodes publish messages to topics and subscribe to topics to receive messages, allowing for anonymous communication between them.
What are Quality of Service (QoS) policies, and why are they important?
- QoS policies define how communication between nodes should be managed under different conditions, ensuring reliability and performance in various network environments.
How can parameters be modified in ROS?
- Parameters can be set for each node either from the command line or by loading configurations from a YASML file, allowing for real-time adjustments.
